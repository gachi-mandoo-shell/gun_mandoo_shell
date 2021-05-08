/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/08 20:41:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_numeric(char *str)
{
	int i;
	
	i = -1;
	while(str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		cmd_exit(t_nd *com, char ***en, char *name)
{
	int		i;
	int		j;
	char	*tmp;
	
	i = 0;
	j = -1;
	write(2, "exit\n", ft_strlen("exit\n"));
	while (com->args[i])
		i++;
	if (i != 1)
	{
		tmp = ft_strtrim(com->args[1], SEP);
		if (!check_numeric(tmp))
		{
			ft_putendl_fd("numeric argument required", 2);
			g_ex.exit_code = 255;
		}
		else
		{
			if (com->args[2] != 0)
			{
				ft_putendl_fd("too many arguments", 2);
				g_ex.exit_code = 1;
				free(tmp);
				return (EXIT_SUCCESS);
			}
			else
				g_ex.exit_code = ft_atoi(tmp);
		}
		free(tmp);
	}
	else
		g_ex.exit_code = 0;
	return (EXIT_FAILURE);
	(void)en;
	(void)name;
}
