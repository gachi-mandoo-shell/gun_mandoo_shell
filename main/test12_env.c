/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:04:18 by skim              #+#    #+#             */
/*   Updated: 2021/04/17 16:41:52 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		cmd_env(t_nd run_com, char **en, char *av)
{
	int		i;

	i = 0;
	while (run_com->args[i])
		i++;
	if (i > 1)
		printf("%s: %s: No such file or directory\n", run_com->args[0], run_cum->args[1]);
	else
	{
		while (en[++i])
			write(1, en[i], ft_strlen(en[i]);
	}
	return (1);
}
