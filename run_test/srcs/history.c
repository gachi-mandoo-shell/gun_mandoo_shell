#include "minishell.h"

t_hist	*history_init()
{
	t_hist	*tmp;

	tmp = malloc(sizeof(tmp) * 1);
	tmp->content = 0;
	tmp->next = 0;
	tmp->prev = 0;

	return (tmp);
}

t_hist	*history_add(t_hist *nd)
{
	t_hist	*tmp;

	if (nd == 0)
	{
		printf("\nfirst!\n");
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		tmp->prev = 0;
	}
	else
	{
		// printf("%s\n", nd->content);
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		nd->next = tmp;
		tmp->prev = nd;
	}

	return (tmp);
}

// void	*history_add(t_hist *nd, char *con)
// {
// 	nd->content = ft_strdup("con");
// 	nd->next = 0;
// 	nd->prev = 0;
// }