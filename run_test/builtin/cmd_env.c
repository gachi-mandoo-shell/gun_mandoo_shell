#include "minishell.h"

int		cmd_env(t_nd *com, char **en, char *av)
{
	int		i;

	i = -1;
	while (en[++i])
		printf("%s\n", en[i]);
	return (EXIT_SUCCESS);
}
