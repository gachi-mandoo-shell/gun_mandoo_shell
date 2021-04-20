#include "minishell.h"

int		get_red(t_nd *nd, int len)
{
	int		i;
	char	tmp[len];
	int		qq_f;
	int		q_f;

	i = -1;
	qq_f = 1;
	q_f = 1;
	while(nd->args[0][++i])
	{

		if (nd->args[0][i] == '\'')
			q_f *= -1;
		else if (nd->args[0][i] == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (nd->args[0][i] == '>' || (nd->args[0][i] == '>' && nd->args[0][i + 1] == '>')))
			nd->re.rdrt_type = RE_TYPE_OUT;
		else if (q_f > 0 && qq_f > 0 && nd->args[0][i] == '<')
			nd->re.rdrt_type = RE_TYPE_IN;
	}
	return (EXIT_SUCCESS);
}

int		lexer(t_nd *new, char *args)
{
	t_nd	*lexer_new;
	t_nd	*anc;
	char	**tok_pipe;
	int		i;

	tok_pipe = split_qoute(args, "|");
	i = -1;
	anc = new;
	while (tok_pipe[++i])
	{
		if (i == 0)
		{
			anc->child = new_nd(tok_pipe[i]);
			get_red(anc->child, ft_strlen(tok_pipe[i]));
			anc->child->prev = anc;
			anc = anc->child;
		}
		else
		{
			anc->sible = new_nd(tok_pipe[i]);
			get_red(anc->sible, ft_strlen(tok_pipe[i]));
			anc->sible->prev = anc;
			anc = anc->sible;
		}
		anc->type = TYPE_C_P;
	}
	anc->type = TYPE_NONE;
	return (EXIT_SUCCESS);
}
