#include "minishell.h"

int		lexer(t_nd *new, char *args)
{
	t_nd	*lexer_new;
	t_nd	*anc;
	char	**tok_pipe;
	int		i;

	tok_pipe = split_qoute(args, '|');
	i = -1;
	anc = new;
	while (tok_pipe[++i])
	{
		lexer_new = new_nd(tok_pipe[i]);
		lexer_new->prev = anc;
		if (i == 0)
			anc->child = lexer_new;
		else
			anc->sible = lexer_new;
		anc = lexer_new;
	}

}
