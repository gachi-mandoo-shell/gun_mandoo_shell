/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_start_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:48:47 by skim              #+#    #+#             */
/*   Updated: 2021/04/16 17:15:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
		// 트리구조의 헤드를 넘겨줄 예정
		read_run(coms);
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
	char	**coms;

	status = 1;
	//start_write();
	while (status)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = read_line();
		coms = make_tok(line, ";");
		status = run_cmd(coms, en, av);
	}
	return (0);
}
