/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:18:53 by spark             #+#    #+#             */
/*   Updated: 2021/04/19 18:55:16 by skim             ###   ########.fr       */
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

int		run_cmd(t_nd *coms, char **en, char *av)
{
	char	**run_com;
	int		rt;
	int		i;

	i = -1;
	rt = 1;
	ready_run(coms);
	print_list(coms);
	coms = coms->child;
	while (coms)
	{
		rt = run(coms, en, av);
		if (coms->sible)
			coms = coms->sible;
		else
			break ;
	}
	return (rt);
}

int		start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	t_nd	*coms;

	status = EXIT_SUCCESS;
	//start_write();
	while (status == EXIT_SUCCESS)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = read_line();
		coms = big_parse(line);
		status = run_cmd(coms, en, av);
	}
	return (0);
}
