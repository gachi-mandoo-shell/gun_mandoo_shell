/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:18:53 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 17:12:49 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(void)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	return (line);
}

int		run_cmd(char **coms, char **en, char *av)
{
	char	**run_com;
	int		rt;
	int		i;
	int		j;

	i = -1;
	rt = 1;
	while (coms[++i])
	{
		run_com = make_tok(coms[i], " ");
		rt = run(run_com, en, av);
		free(coms[i]);
		j = -1;
		while (run_com[++j])
			free(run_com[j]);
		if (run_com)
			free(run_com);
	}
	return (rt);
}

int		start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	t_nd	*coms;

	status = 1;
	while (status)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = read_line();
		coms = pharse(line, ";");
		// status = run_cmd(coms, en, av);
	}
	return (0);
}
