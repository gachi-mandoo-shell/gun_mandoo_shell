#include "minishell.h"

int		pipe_dup(t_nd *cmd)
{
	int		err_check;

	if (cmd->type == TYPE_C_P)
		err_check = dup2(cmd->pipes[SIDE_IN], STDOUT);
	if (err_check < 0)
		return (EXIT_FAILURE);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
	{
		// printf("here : %s\n", cmd->args[0]);
		// char buf[1000];
		// read(cmd->prev->pipes[SIDE_OUT], buf, 1000);
		// printf(">>%s\n", buf);
		err_check = dup2(cmd->prev->pipes[SIDE_OUT], STDIN);
	}
	if (err_check < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	pipe_close(t_nd *cmd)
{
	close(cmd->pipes[SIDE_IN]);
	if (cmd->sible == NULL)
		close(cmd->pipes[SIDE_OUT]);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
		close(cmd->prev->pipes[SIDE_OUT]);
}

/*************************************/
/*			내부 함수 일 경우			 */
/*************************************/

int		execute_ps(char *run_com, t_nd *com, char **en, char *name)
{
	pid_t	pid;
	int		rt;

	if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
		pipe(com->pipes);
	if (com->re.rdrt_type > 0 && com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
		dup2(com->re.rdrt_fd, com->pipes[SIDE_IN]);
	pid = fork();
	if (pid == 0)
	{
		// signal(SIGINT, (void*)signal_child_ctlc);
		if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
			pipe_dup(com);
		else
		{
			if (com->re.rdrt_type > 0)
				dup2(com->re.rdrt_fd, STDOUT);
		}
		rt = execve(run_com, com->args, en);
		if (rt == -1)
			printf("%s: %s\n", run_com, strerror(errno));
		exit(rt);
	}
	else if (pid > 0)
	{
		wait(&pid);
		if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
			pipe_close(com);
	}
	else
		write(1, "failed to fork", ft_strlen("failed to fork"));
	return (EXIT_SUCCESS);
}

void	find_cmd(t_nd *com, char **en, char *av)
{
	struct stat	test;
	char		**bash_path;
	char		temp_path[PATH_MAX];
	int			i;

	i = -1;
	bash_path = make_tok(find_env_val("PATH", en), ":");
	while (bash_path[++i])
	{
		ft_memset(temp_path, '\0', PATH_MAX);
		strcat(temp_path, bash_path[i]);
		if (com->args[0][0] != '/')
			strcat(temp_path, "/");
		strcat(temp_path, com->args[0]);
		// printf("find : %s\n", temp_path);
		if (stat(temp_path, &test) != -1)
		{
			execute_ps(temp_path, com, en, av);
			break ;
		}
	}
	if (bash_path[i] == NULL)
		printf("%s: %s\n", temp_path, strerror(errno));
	i = -1;
	while (bash_path[++i])
		free(bash_path[i]);
	free(bash_path);
}

/*************************************/
/*			built_in 일 경우		   */
/*************************************/

char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "exit";
	blt_str[1] = "env";
	blt_str[2] = "pwd";
	blt_str[3] = "cd";
	blt_str[BLT_NUM] = NULL;
	return (blt_str[i]);
}

int	(*blt_func(int i))(t_nd *cmd, char **en, char *av)
{
	int		(*blt_fuck[BLT_NUM])(t_nd *cmd, char **en, char *av);

	blt_fuck[0] = &cmd_exit;
	blt_fuck[1] = &cmd_env;
	blt_fuck[2] = &cmd_pwd;
	blt_fuck[3] = &cmd_cd;
	return (blt_fuck[i]);
}

int		builtin_run(t_nd *cmd, char **en, char *av, int i)
{
	int 	rt;
	pid_t	pid;

	if (cmd->type == TYPE_C_P || (cmd->prev && cmd->prev->type == TYPE_C_P))
	{
		pipe(cmd->pipes);
		if (cmd->re.rdrt_type > 0)
			dup2(cmd->re.rdrt_fd, cmd->pipes[SIDE_IN]);
		pid = fork();
		if (pid == 0)
		{
			pipe_dup(cmd);
			// kill(pid, SIGINT);
			// signal(SIGTERM, (void*)signal_child_ctld);
			// signal(SIGQUIT, (void*)signal_child_ctlslash);
			rt = (*blt_func(i))(cmd, en, av);
		}
		else if (pid > 0)
		{
			wait(&pid);
			// pipe_close(cmd);
		}
		else
			write(1, "failed to fork", ft_strlen("failed to fork"));
	}
	else
	{
		if (cmd->re.rdrt_type > 0)
			dup2(cmd->re.rdrt_fd, STDOUT);
		rt = (*blt_func(i))(cmd, en, av);
	}
	return (rt);
}


/*************************************/
/*			run을 분류하는 함수			 */
/*************************************/


int		run_div(t_nd *cmd, char **en, char *av)
{
	struct stat	test;
	int i;
	int rt;

	i = -1;
	rt = EXIT_SUCCESS;
	while (++i < BLT_NUM)
		if (!(strcmp(cmd->args[0], blt_str(i))))
			return (builtin_run(cmd, en, av, i));
	if (stat(cmd->args[0], &test) != -1)
		execute_ps(cmd->args[0], cmd, en, av);
	else
		find_cmd(cmd, en, av);
	return (rt);
}

int		run(t_nd *cmd, char **en, char *av)
{
	int rt;

	rt = EXIT_SUCCESS;
	while (cmd && rt == EXIT_SUCCESS)
	{
		// int a = 0;
		// while (cmd->args[a])
		// 	printf("%d : %s\n", a, cmd->args[a++]);
		rt = run_div(cmd, en, av);
		if (cmd->re.rdrt_type > 0)
			close(cmd->re.rdrt_fd);
		if (cmd->sible)
			cmd = cmd->sible;
		else
			break ;
	}
	return (rt);
}
