/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:19:11 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 21:16:11 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char ***env, char *en[])
{
	int		i;
	int		j;

	i = 0;
	while (en[i])
		i++;
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	(*env)[i] = 0;
	j = -1;
	while (++j < i)
		(*env)[j] = ft_strdup(en[j]);
}

int		main(int ac, char *av[], char *en[])
{
	char	**env;
	char	rt;

	init_env(&env, en);
	rt = start_shell(env, av[0]);
}
