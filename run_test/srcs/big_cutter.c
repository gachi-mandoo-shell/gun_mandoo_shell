#include "minishell.h"

t_nd	*big_cutter(char *str)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = -1;

	tmp = split_quote(str, ";");

	// while (tmp[++i])
	// 	printf("%d : %s\n", i, tmp[i]);
	// i = -1;

	mother = new_nd(str);
	mother->pos.head = mother;
	mother->pos.tail = mother;
	while (tmp[++i])
	{
		if (i == 0)
		{
			mother->child = new_nd(tmp[i]);
			mother->child->prev = mother;
			tmp_nd = mother->child;
		}
		else
		{
			tmp_nd->sible = new_nd(tmp[i]);
			tmp_nd->sible->prev = tmp_nd;
			tmp_nd = tmp_nd->sible;
		}
	}
	tmp_nd = mother;
	// printf("{ %s }\n", tmp_nd->args[0]);
	// while(tmp_nd->child)
	// {
	// 	tmp_nd = tmp_nd->child;
	// 	while(tmp_nd->sible)
	// 	{
	// 		printf(" -> { %s }",tmp_nd->args[0]);
	// 		tmp_nd = tmp_nd->sible;
	// 	}
	// 	printf(" -> { %s }",tmp_nd->args[0]);
	// }
	// printf("\n");
	return (mother);
}
