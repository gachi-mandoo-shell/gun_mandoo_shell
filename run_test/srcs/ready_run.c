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
		if (anc->sible)
			anc = anc->sible;
	}
	//mini tok 해야하는 부분
	while (anc)
	{
		new = new_nd(0);
		// mini_tok;
		new->args = make_tok(anc->args[0], SEP);
		new->pos.head = coms;
		new->prev = anc;
		anc->child = new;
		anc = anc->sible;
	}
}
