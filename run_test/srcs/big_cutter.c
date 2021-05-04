

#include "minishell.h"

t_nd	*big_cutter(char *str)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = -1;
	if (!tmp)
		return (NULL);
	tmp = split_quote(str, ";");
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
	return (mother);
}
