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

void	free_nd(t_nd *coms)
{
	t_nd	*tmp;
	t_nd	*nd_erase;

	tmp = coms;
	while (tmp->sible)
		tmp = tmp->sible;
	if (tmp->child)
		free_nd(tmp->child);
	while (tmp)
	{
		nd_erase = tmp;
		free_nd_data(nd_erase);
		if (tmp->prev)
		{
			tmp = tmp->prev;
			free(nd_erase);
		}
		else
		{
			free(tmp);
			tmp = 0;
		}
	}
}

void	free_hist(t_hist *hist)
{
	t_hist	*tmp1;
	t_hist	*tmp2;

	tmp1 = hist;
	tmp2 = 0;
	while (tmp1)
	{
		if (tmp1->prev)
			tmp2 = tmp1->prev;
		if (tmp1->content)
			free(tmp1->content);
		free(tmp1);
		if (tmp2)
			tmp1 = tmp2;
		else
			break ;
		tmp2 = 0;
	}
}
