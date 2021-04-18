/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:19:02 by spark             #+#    #+#             */
/*   Updated: 2021/04/17 23:25:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	(*blt_func(int i))(char **run_com, char **en, char *av)
{
	int		(*blt_fuck[BLT_NUM])(char **run_com, char **en, char *av);

	blt_fuck[0] = &cmd_exit;
	blt_fuck[1] = &cmd_env;
	blt_fuck[2] = &cmd_pwd;
	blt_fuck[3] = &cmd_cd;
	return (blt_fuck[i]);
}

int	execute_ps(char *run_com, char **av, char **en, char *name)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(run_com, av, en) == -1)
			write(1, "permission denied", ft_strlen("permission denied"));
	}
	else if (pid < 0)
		write(1, "failed to fork", ft_strlen("failed to fork"));
	else
		wait(&pid);
	return (1);
}

void	find_cmd(char **run_com, char **en, char *av)
{
	char	**bash_path;
	char	temp_path[PATH_MAX];
	int		i;

	i = -1;
	bash_path = make_tok(find_env("PATH", en), ":");
	while (bash_path[++i])
	{
		ft_memset(temp_path, '\0', PATH_MAX);
		strcat(temp_path, bash_path[i]);
		if (run_com[0][0] != '/')
			strcat(temp_path, "/");
		strcat(temp_path, run_com[0]);
		if (access(temp_path, F_OK) != -1)
		{
			execute_ps(temp_path, run_com, en, av);
			break ;
		}
	}
	i = -1;
	while (bash_path[++i])
		free(bash_path[i]);
	free(bash_path);
}

int	run(char **run_com, char **en, char *av)
{
	int		i;
	int		rt;

	rt = 1;
	i = -1;
	if (!run_com || !*run_com || !**run_com)
		return (rt);
	while (++i < BLT_NUM)
		if (!(strcmp(run_com[0], blt_str(i))))
			return ((*blt_func(i))(run_com, en, av));
	if (access(run_com[0], F_OK) != -1)
		execute_ps(run_com[0], run_com, en, av);
	else
		find_cmd(run_com, en, av);
	return (rt);
}
