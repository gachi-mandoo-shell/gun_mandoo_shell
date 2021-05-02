#include "minishell.h"

int		cmd_env(t_nd *com, char ***en, char *av)
{
	int		i;

	i = -1;
	if (com->args[1])
	{
		printf("%s: %s: No such file or directory\n", com->args[0], com->args[1]);
		g_ex.exit_code = 127;
		return (EXIT_SUCCESS);
	}
	while ((* en)[++i])
		printf("%s\n", (* en)[i]);
	g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
}
