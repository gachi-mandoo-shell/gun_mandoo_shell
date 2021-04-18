/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:18:53 by spark             #+#    #+#             */
/*   Updated: 2021/04/18 22:37:22 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_args(char **args)
{
	int i;
	
	i = -1;
	while (args[++i])
		printf("{%s},", args[i]);
}

void	print_list(t_nd *com)
{
	t_nd *tmp_nd;
	t_nd *tmp_nd2;
	
	tmp_nd = com;
	tmp_nd2 = com;
	print_args(tmp_nd->args);
	printf("\n");
	if (tmp_nd2->child)
	{
		tmp_nd2 = tmp_nd2->child;
		tmp_nd = tmp_nd2;
		print_list(tmp_nd2);
		printf("\n====================\n");
	}
	while(tmp_nd->sible)
	{
		tmp_nd = tmp_nd->sible;
		print_list(tmp_nd);
	}
}

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

t_nd	*new_nd(char *name)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	if (name != NULL)
	{
		tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
		if (!tmp_nd->args)
			return (NULL);
		tmp_nd->args[0] = ft_strdup(name);
		tmp_nd->args[1] = 0;
	}
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
	// printf("{ %s }\n", tmp_nd->args[0]);
	// while(tmp_nd->child)
	// {
	// 	tmp_nd = tmp_nd->child;
	// 	while(tmp_nd->sible)
	// 	{
	// 		printf(" -> { %s }",tmp_nd->args[0]);
	// 		tmp_nd = tmp_nd->sible;
	// 	}
	// 	printf(" -> { %s }",tmp_nd->args[0]);
	// }
	// printf("\n");
	return (mother);
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
		coms = parse(line, ";");
		// coms = coms->child;
		status = run_cmd(coms, en, av);
	}
	return (0);
}
