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
		if (i == 0)
		{
			anc->child = new_nd(tok_pipe[i]);
			anc = anc->child;
		}
		else
		{
			anc->sible = new_nd(tok_pipe[i]);
			anc = anc->sible;
		}
		anc->type = TYPE_PIPE_C_P
	}

	return (EXIT_SUCCESS);
}
