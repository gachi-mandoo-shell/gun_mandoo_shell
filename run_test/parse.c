
// t_nd	*new_nd(char *name)
// {
// 	t_nd	*tmp_nd;

// 	tmp_nd = malloc(sizeof(t_nd) * 1);
// 	if (!tmp_nd)
// 		return (NULL);
// 	tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
// 	if (!tmp_nd->args)
// 		return (NULL);
// 	tmp_nd->args[0] = ft_strdup(name);
// 	tmp_nd->args[1] = 0;
// 	tmp_nd->child = 0;
// 	tmp_nd->sible = 0;
// 	tmp_nd->prev = 0;
// 	tmp_nd->type = -1;
// 	tmp_nd->pos.head = 0;
// 	tmp_nd->pos.tail = 0;
// 	tmp_nd->re.rdrt_yn = 0;
// 	tmp_nd->re.rdrt_fd = 0;
// 	return (tmp_nd);
// }

// t_nd	*parse(char *str, char *charset)
// {
// 	char	**tmp;
// 	int		i;
// 	t_nd	*mother;
// 	t_nd	*tmp_nd;
// 	t_nd	*tmp_nd2;

// 	i = -1;
// 	tmp = make_tok(str, charset);
// 	// while (tmp[++i])
// 	// 	printf(" -> %s\n", tmp[i]);

// 	// i = -1;
// 	// 빅 토큰라인들이 들어있는 tmp
// 	mother = new_nd(str);
// 	mother->pos.head = mother;
// 	mother->pos.tail = mother;
// 	while (tmp[++i])
// 	{
// 		if (i == 0)
// 		{
// 			mother->child = new_nd(tmp[i]);
// 			mother->child->prev = mother;
// 			tmp_nd = mother->child;
// 		}
// 		else
// 		{
// 			tmp_nd->sible = new_nd(tmp[i]);
// 			tmp_nd->sible->prev = tmp_nd;
// 			tmp_nd = tmp_nd->sible;
// 		}
// 	}
// 	tmp_nd = mother;
// 	printf("{ %s }\n", tmp_nd->args[0]);
// 	while(tmp_nd->child)
// 	{
// 		tmp_nd = tmp_nd->child;
// 		while(tmp_nd->sible)
// 		{
// 			printf(" -> { %s }",tmp_nd->args[0]);
// 			tmp_nd = tmp_nd->sible;
// 		}
// 		printf(" -> { %s }",tmp_nd->args[0]);
// 	}
// 	printf("\n");
// 	return (mother);
// }

// int		start_shell(char **en, char *av)
// {
// 	int		status;
// 	char	*line;
// 	t_nd	*coms;

// 	status = 1;
// 	//start_write();
// 	while (status)
// 	{
// 		write(1, "minishell test> ", ft_strlen("minishell test> "));
// 		line = read_line();
// 		coms = parse(line, ";");
// 		coms = coms->child;
// 		status = run_cmd(coms, en, av);
// 	}
// 	return (0);
// }

#include "minishell.h"

t_nd	*child_rewind(t_nd *coms)
{
	t_nd	*tmp;

	tmp = coms;
	while (tmp->child)
		tmp = tmp->child;
	return (tmp);
}

int	matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
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
		new->args = make_tok(anc->args[0], SEP);
		new->pos.head = coms;
		new->prev = anc;
		anc->child = new;
		anc = anc->sible;
	}
}	