#include "minishell.h"

int	is_redirect(char *str)
{
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>") || !ft_strcmp(str, "<"))
		return (1);
	else
		return (0);
}

int	change_arg(t_nd *nd, int arg_count)
{
	char	**c_arg;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < arg_count)
	{
		if (nd->args[i])
			count++;
	}
	c_arg = malloc(sizeof(char *) * (count + 1));
	if (!c_arg)
		return (EXIT_FAILURE);
	c_arg[count] = 0;
	i = -1;
	count = 0;
	while (++i < arg_count)
	{
		if (nd->args[i])
		{
			c_arg[count++] = ft_strdup(nd->args[i]);
			free(nd->args[i]);
		}
	}
	free(nd->args);
	nd->args = c_arg;
	return (EXIT_SUCCESS);
}

int	get_redirect(t_nd *nd, char **en)
{
	t_nd	*anc;
	int		arg_count;
	int		red_pos;
	int		rt;

	anc = nd;
	while (anc)
	{
		arg_count = -1;
		while (anc->args[++arg_count])
		{
			if (is_redirect(anc->args[arg_count]))
				get_redirect_info(anc, arg_count++, en);
		}
		if (change_arg(anc, arg_count) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (anc->sible)
			anc = anc->sible;
		else
			break ;
	}
	return (EXIT_SUCCESS);
}
