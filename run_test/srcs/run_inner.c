#include "minishell.h"

int		execute_ps(char *run_com, t_nd *com, char **en, char *name)
{
	pid_t	pid;
	int		rt;

	if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
		pipe(com->pipes);
	if (com->re.rdrt_type > 0 && com->type == TYPE_C_P)
		dup2(com->re.rdrt_fd, com->pipes[SIDE_IN]);
	if (com->re.rdrt_in_type > 0 && com->type == TYPE_C_P)
		dup2(com->re.rdrt_in_fd, com->pipes[SIDE_OUT]);
	pid = fork();
	if (pid == 0)
	{
		if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
			pipe_dup(com);
		if (com->type != TYPE_C_P)
		{
			if (com->re.rdrt_type > 0)
				dup2(com->re.rdrt_fd, STDOUT);
			if (com->re.rdrt_in_type > 0)
				dup2(com->re.rdrt_in_fd, com->pipes[SIDE_OUT]);
		}
		if (run_com)
			rt = execve(run_com, com->args, en);
		// printf("\nexceve rt is %d!\n\n",rt);
		if (rt == -1)
			printf("%s: %s\n", run_com, strerror(errno));
		exit(rt);
	}
	else if (pid > 0)
	{
		wait(&exit_code);
		if (com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P))
			pipe_close(com);
		// printf("\n<<mother's exit_code is %d!>>\n\n",exit_code);
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
	bash_path = split_quote(find_env_val("PATH", en), ":");
	while (bash_path[++i])
	{
		if (com->args[0])
		{
			ft_memset(temp_path, '\0', PATH_MAX);
			strcat(temp_path, bash_path[i]);
			if (com->args[0][0] != '/')
				strcat(temp_path, "/");
			strcat(temp_path, com->args[0]);
			if (stat(temp_path, &test) != -1)
			{
				execute_ps(temp_path, com, en, av);
				break ;
			}
		}
		else
		{
			execute_ps(com->args[0], com, en, av);
			break ;
		}
	}
	if (bash_path[i] == NULL)
		printf("%s: %s\n", com->args[0], strerror(errno));
	i = -1;
	while (bash_path[++i])
		free(bash_path[i]);
	free(bash_path);
}
