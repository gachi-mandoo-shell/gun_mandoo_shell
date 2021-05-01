#include "minishell.h"

int	cmd_unset(t_nd *com, char ***en, char *av)
{
	char *tmp;
	char **new_en;
	int i;
	int	j;

	i = -1;
	j = -1;
	if (!com->args[1]) 
		return (EXIT_SUCCESS);
	tmp = find_env(com->args[1], *en);
	if (!tmp)
		return (EXIT_SUCCESS);
	new_en = malloc(sizeof(char*) * (matrix_line_num(*en)));
	if (!new_en)
		return (EXIT_FAILURE);
	while ((*en)[++i])
	{
		if ((*en)[i] != tmp)
			new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free((*en)[i]);
	new_en[++j] = 0;
	(*en) = new_en;
	return(EXIT_SUCCESS);
}