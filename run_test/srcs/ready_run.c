#include "minishell.h"

t_nd	*child_rewind(t_nd *coms)
{
	t_nd	*tmp;

	tmp = coms;
	while (tmp->child)
		tmp = tmp->child;
	return (tmp);
}

void	ready_run(t_nd *coms)
{
	t_nd	*anc;
	t_nd	*new;
	char	**temp_tok;

	anc = child_rewind(coms);
	while (anc)
	{
		lexer(anc, anc->args[0]);
		make_mini_tok(anc->child);
		if (anc->sible)
			anc = anc->sible;
	}
}
