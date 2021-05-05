#include "minishell.h"

t_hist	*history_add(t_hist *nd)
{
	t_hist	*tmp;

	if (nd == 0)
	{
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		tmp->prev = 0;
		tmp->count = 0;
	}
	else
	{
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		nd->next = tmp;
		tmp->prev = nd;
		tmp->count = nd->count + 1;
	}
	return (tmp);
}
