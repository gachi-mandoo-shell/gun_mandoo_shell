/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:01:44 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 23:20:29 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free((*matrix));
}

int		matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	check_quote(char c, int *q_f, int *qq_f)
{
	if (c == '\'')
		(*q_f) *= -1;
	else if (c == '\"')
		(*qq_f) *= -1;
}
