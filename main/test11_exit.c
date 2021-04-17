/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:58:03 by skim              #+#    #+#             */
/*   Updated: 2021/04/17 16:14:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		cmd_exit(t_nd run_com, char **en, char *name)
{
	int		i;

	i = 0;
	while (run_com->args[i])
		i++;
	printf("exit\n");
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		return (1);
	}
	else
		return (0);
}
