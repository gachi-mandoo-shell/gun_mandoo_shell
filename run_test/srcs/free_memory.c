#include "minishell.h"

void	free_nd_data(t_nd *coms)
{
	int	i;

	i = -1;
	if (coms->re.rdrt_name)
		free(coms->re.rdrt_name);
	if (coms->re.rdrt_in_name)
		free(coms->re.rdrt_in_name);
	while (coms->args[++i])
		free(coms->args[i]);
	if (coms->args)
		free(coms->args);
}

void	free_sible(t_nd *coms)
{
	t_nd *tmp;
	t_nd *nd_erase;

	tmp = coms;
	while (tmp->sible)
		tmp = tmp->sible;
	if (tmp->child)
		free_sible(tmp->child);
	
	while (tmp)
	{
		free_nd_data(tmp);
		nd_erase = tmp;
		if (tmp->prev)
			tmp = tmp->prev;
		free(nd_erase);
	}
}

void	free_nd(t_nd *coms)
{
	t_nd *tmp;
	
	tmp = coms->child;
	free_nd_data(coms);
	free_sible(tmp);
	free(coms);
}