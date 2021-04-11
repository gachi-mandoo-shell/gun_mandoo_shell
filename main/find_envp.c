/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:26:20 by skim              #+#    #+#             */
/*   Updated: 2021/04/11 17:31:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *key, char **en)
{
	int		i;

	i = -1;
	while (en[++i])
	{
		if (!strncmp(key, en[i], ft_strlen(key)))
			return (en[i]);
	}
	return (0);
}
