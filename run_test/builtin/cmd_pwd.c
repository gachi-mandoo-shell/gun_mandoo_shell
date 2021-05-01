#include "minishell.h"

int		cmd_pwd(t_nd *com, char ***en, char *av)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}
