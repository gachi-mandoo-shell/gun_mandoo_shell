#include "minishell.h"

int		cmd_exit(t_nd *com, char **en, char *name)
{
	int		i;

	i = 0;
	while (com->args[i])
		i++;
	printf("exit\n");
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
