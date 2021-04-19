#include "minishell.h"

int		count_size(char *str)
{
	int		count;
	int		i;
	int		qq_f;
	int		q_f;

	count = 1;
	i = -1;
	qq_f = 1;
	q_f = 1;
	while (str[++i])
	{
		if (str[i] == '\"')
			qq_f *= -1;
		else if (str[i] == '\'')
			q_f *= -1;
		else if (str[i] == ';' && qq_f > 0 && q_f > 0)
			count++;
	}
	return (count);
}

char	*sep(char **str)
{
	char	*rt;
	int		i;
	int		qq_f;
	int		q_f;

	i = -1;
	qq_f = 1;
	q_f = 1;
	while ((*str)[++i])
	{
		if ((*str)[i] == '\"')
			qq_f *= -1;
		else if ((*str)[i] == '\'')
			q_f *= -1;
		if ((*str)[i] == ';' && qq_f > 0 && q_f > 0)
			break;
	}
	if (!(*str)[i])
		rt = ft_strndup(*str, i);
	else
	{
		rt = ft_strndup(*str, i);
		(*str) += i + 1;
	}
	return (rt);
}

char	**make_big_tok(char *str)
{
	char	**rt;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = count_size(str);
	rt = (char **)malloc(sizeof(char *) * (size + 1));
	if (!rt)
		return (NULL);
	i = -1;
	while (++i < size)
		rt[i] = sep(&str);
	rt[i] = 0;
	return (rt);
}

t_nd	*big_parse(char *str)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = -1;
	tmp = make_big_tok(str);

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
