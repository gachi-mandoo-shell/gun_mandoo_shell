#include "minishell.h"

int		is_redirect(char *str)
{
	if (!strcmp(str, ">") || !strcmp(str, ">>") || !strcmp(str, "<"))
		return (1);
	else
		return (0);
}

int		redirect_check(char **args)
{
	int	args_count;

	args_count = -1;
	while (args[++args_count])
	{
		if (is_redirect(args[args_count]))
			if (!args[args_count + 1] || is_redirect(args[args_count + 1]))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		syntax_check(t_nd *nd)
{
	char	*tmp;
	t_nd	*tmp_nd;
	int		i;

	i = -1;
	tmp_nd = nd;
	while (nd)
	{
		tmp = ft_strdup(tmp_nd->args[0]);
		free(tmp_nd->args[0]);
		free(tmp_nd->args);
		tmp_nd->args = split_qoute(tmp, SEP);
		free(tmp);
		if (redirect_check(tmp_nd->args))
			return (EXIT_FAILURE);
		if (tmp_nd->sible)
			tmp_nd = tmp_nd->sible;
		else 
			break;
	}
	return (EXIT_SUCCESS);
}

