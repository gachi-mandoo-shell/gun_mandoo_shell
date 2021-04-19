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
		new = new_nd(0);
		lexer(new, anc->args[0]);
		new->pos.head = coms;
		new->prev = anc;
		anc->child = new;
		anc = anc->sible;
	}
	
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
