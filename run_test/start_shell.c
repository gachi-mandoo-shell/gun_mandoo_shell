/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:18:53 by spark             #+#    #+#             */
/*   Updated: 2021/04/17 22:00:43 by skim             ###   ########.fr       */
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
	int		j;

	i = -1;
	rt = 1;
	while (coms)
	{
		run_com = make_tok(coms->args[0], " ");
		// 트리구조의 헤드를 넘겨줄 예정
		//ready_run(coms);
		rt = run(run_com, en, av);
		j = -1;
		coms = coms->sible;
	}
	return (rt);
}

t_nd	*new_nd(char *name)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
	if (!tmp_nd->args)
		return (NULL);
	tmp_nd->args[0] = ft_strdup(name);
	tmp_nd->args[1] = 0;
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->prev = 0;
	tmp_nd->type = -1;
	tmp_nd->pos.head = 0;
	tmp_nd->pos.tail = 0;
	tmp_nd->re.rdrt_yn = 0;
	tmp_nd->re.rdrt_fd = 0;
	return (tmp_nd);
}

t_nd	*parse(char *str, char *charset)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = -1;
	tmp = make_tok(str, charset);
	// while (tmp[++i])
	// 	printf(" -> %s\n", tmp[i]);

	// i = -1;
	// 빅 토큰라인들이 들어있는 tmp
	mother = new_nd(str);
	mother->pos.head = mother;
	mother->pos.tail = mother;
	while (tmp[++i])
	{
		if (i == 0)
		{
			mother->child = new_nd(tmp[i]);
			mother->child->prev = mother;
			tmp_nd = mother->child;
		}
		else
		{
			tmp_nd->sible = new_nd(tmp[i]);
			tmp_nd->sible->prev = tmp_nd;
			tmp_nd = tmp_nd->sible;
		}
	}
	tmp_nd = mother;
	printf("{ %s }\n", tmp_nd->args[0]);
	while(tmp_nd->child)
	{
		tmp_nd = tmp_nd->child;
		while(tmp_nd->sible)
		{
			printf(" -> { %s }",tmp_nd->args[0]);
			tmp_nd = tmp_nd->sible;
		}
		printf(" -> { %s }",tmp_nd->args[0]);
	}
	printf("\n");

	return	mother;
}

int		start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	t_nd	*coms;

	status = 1;
	//start_write();
	while (status)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = read_line();
		coms = parse(line, ";");
		coms = coms->child;
		status = run_cmd(coms, en, av);
	}
	return (0);
}
