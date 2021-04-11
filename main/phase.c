/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:22:04 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 20:35:42 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nd	*new_nd(int depth)
{
	t_nd*	tmp_nd;
	
	tmp_nd = malloc(sizeof(t_nd) * 1);
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->val = 0;
	tmp_nd->dep = depth;
	
	return (tmp_nd);
}

t_nd	*pharse(char *str, char *charset)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = 0;
	tmp = make_tok(str, charset);
	mother = new_nd(0);
	mother->val = ft_strdup(str); 
	mother->dep = 0;
	if (tmp[0])
	{
		mother->child = new_nd(1);
		mother->child->val = ft_strdup(tmp[0]);
		tmp_nd = mother->child;
	}
	while(tmp[++i])
	{
		tmp_nd->sible = new_nd(1);
		tmp_nd->sible->val = ft_strdup(tmp[i]);
		tmp_nd = tmp_nd->sible;
	}
	tmp_nd = mother;
	printf("{ %s }", tmp_nd->val);
	while(tmp_nd->child)
	{
		printf("\n|\n -> { %s }",tmp_nd->child->val);
		tmp_nd = tmp_nd->child;
		while(tmp_nd->sible)
		{
			printf(" -> { %s }",tmp_nd->sible->val);
			if(tmp_nd->sible)
				tmp_nd = tmp_nd->sible;
		}
	}
	printf("\n");
	
	return	mother;
}