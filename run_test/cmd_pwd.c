#include "minishell.h"

int		cmd_pwd(char **run_cum, char **en, char *av)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
	return (1);
}
