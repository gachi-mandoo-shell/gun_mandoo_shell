/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:14 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 07:31:21 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char *str)
{
	if (ft_isdigit(str[0]) || ft_strchr(str, '='))
	{
		g_ex.exit_code = -1;
		write(2, "not a valid identifier\n", \
		ft_strlen("not a valid identifier\n"));
		return (0);
	}
	return (1);
}

int	cmd_unset(t_nd *com, char ***en, char *av)
{
	char	*tmp;
	char	**new_en;
	int		i;

	if (!com->args[1])
	{
		g_ex.exit_code = 0;
		return (EXIT_SUCCESS);
	}
	i = 0;
	while (com->args[++i])
	{
		tmp = find_env(com->args[i], en);
		if (tmp && check_arg(com->args[i]))
		{
			new_en = delete_env(en, tmp);
			(*en) = new_en;
		}
	}
	if (g_ex.exit_code < 0)
		g_ex.exit_code = 1;
	else
		g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
	(void)av;
}
