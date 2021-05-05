#include "minishell.h"

int	tokenizer(t_nd *nd)
{
	char	*tmp;
	t_nd	*tmp_nd;
	char	**before_arg;
	int		i;

	i = -1;
	if (synerror_redirect(nd->args[0]))
		return (EXIT_FAILURE);
	tmp_nd = nd;
	while (tmp_nd)
	{
		tmp = ft_strdup(tmp_nd->args[0]);
		free(tmp_nd->args[0]);
		free(tmp_nd->args);
		before_arg = split_quote(tmp, SEP);
		tmp_nd->args = split_redirect(before_arg);
		free(tmp);
		if (tmp_nd->sible)
			tmp_nd = tmp_nd->sible;
		else
			break ;
	}
	i = 0;
	while (before_arg[i])
		free(before_arg[i++]);
	free(before_arg);
	return (EXIT_SUCCESS);
}

int	lexer(t_nd *new, char *args)
{
	t_nd	*lexer_new;
	t_nd	*anc;
	char	**tok_pipe;
	int		i;

	if (synerror_checker(args, '|') < 0)
		return (EXIT_FAILURE);
	tok_pipe = split_quote(args, "|");
	i = -1;
	anc = new;
	while (tok_pipe[++i])
	{
		if (i == 0)
		{
			anc->child = new_nd(tok_pipe[i]);
			anc = anc->child;
		}
		else
		{
			anc->sible = new_nd(tok_pipe[i]);
			anc->sible->prev = anc;
			anc = anc->sible;
		}
		anc->type = TYPE_C_P;
	}
	anc->type = TYPE_NONE;
	return (EXIT_SUCCESS);
}
