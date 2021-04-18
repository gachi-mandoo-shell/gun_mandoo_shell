/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:58:03 by skim              #+#    #+#             */
/*   Updated: 2021/04/18 22:37:41 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_exit(t_nd *com, char **en, char *name)
{
	int		i;

	i = 0;
	while (com->args[i])
		i++;
	printf("exit\n");
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
