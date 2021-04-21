#include "minishell.h"

t_nd	*new_nd(char *name)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	if (name != NULL)
	{
		tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
		if (!tmp_nd->args)
			return (NULL);
		tmp_nd->args[0] = ft_strdup(name);
		tmp_nd->args[1] = 0;
	}
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->prev = 0;
	tmp_nd->type = -1;
	tmp_nd->pos.head = 0;
	tmp_nd->pos.tail = 0;
	tmp_nd->re.rdrt_type = 0;
	tmp_nd->re.rdrt_fd = 0;
	return (tmp_nd);
}

void	print_args(char **args)
{
	int i;

	i = -1;
	while (args[++i])
		printf("{%s},", args[i]);
}

void	print_list(t_nd *com)
{
	t_nd *tmp_nd;
	t_nd *tmp_nd2;

	tmp_nd = com;
	tmp_nd2 = com;
	print_args(tmp_nd->args);
	printf("\n");
	if (tmp_nd2->child)
	{
		tmp_nd2 = tmp_nd2->child;
		tmp_nd = tmp_nd2;
		printf("->");
		print_list(tmp_nd2);
		// printf("\n====================\n");
	}
	while(tmp_nd->sible)
	{
		tmp_nd = tmp_nd->sible;
		print_list(tmp_nd);
	}
}

int	matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
