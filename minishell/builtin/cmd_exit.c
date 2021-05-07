/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 18:17:32 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_exit(t_nd *com, char ***en, char *name)
{
	int		i;

	i = 0;
	while (com->args[i])
		i++;
	write(2, "exit\n", ft_strlen("exit\n"));
	g_ex.exit_code = 0;
	if (i > 2)
	{
		write(2, "exit: too many arguments\n", \
		ft_strlen("exit: too many arguments\n"));
		g_ex.exit_code = 1;
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
	(void)en;
	(void)name;
}
