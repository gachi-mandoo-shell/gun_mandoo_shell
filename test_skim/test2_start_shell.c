/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2_start_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:48:47 by skim              #+#    #+#             */
/*   Updated: 2021/04/16 21:38:07 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

parpar4parparpar:09par#include "test.h"

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

t_nd	*new_nd(int depth)
{
	t_nd*	tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->prev = 0;
	tmp_nd->type = -1;

	tmp_nd->val = 0;
	tmp_nd->dep = depth;

	return (tmp_nd);
}

t_nd	*parse(char *str, char *charset)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = 0;
	tmp = make_tok(str, charset);
	// 빅 토큰라인들이 들어있는 tmp
	mother = new_nd(0);
	mother->val = ft_strdup(str);
	mother->dep = 0;
	if (tmp[0])
	{
		mother->child = new_nd(1);
		mother->child->val = ft_strdup(tmp[0]);
		tmp_nd = mother->child;
	}
	while(tmp[++i])
	{
		tmp_nd->sible = new_nd(1);
		tmp_nd->sible->val = ft_strdup(tmp[i]);
		tmp_nd = tmp_nd->sible;
	}
	tmp_nd = mother;
	printf("{ %s }", tmp_nd->val);
	while(tmp_nd->child)
	{
		printf("\n|\n -> { %s }",tmp_nd->child->val);
		tmp_nd = tmp_nd->child;
		while(tmp_nd->sible)
		{
			printf(" -> { %s }",tmp_nd->sible->val);
			if(tmp_nd->sible)
				tmp_nd = tmp_nd->sible;
		}
	}
	printf("\n");

	return	mother;
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
		coms = parse(line, ";");
		status = run_cmd(coms, en, av);
	}
	return (0);
}
