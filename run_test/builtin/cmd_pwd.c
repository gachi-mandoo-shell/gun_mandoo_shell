#include "minishell.h"

int		cmd_pwd(t_nd *com, char ***en, char *av)
{
	char	*pwd;

	pwd = find_env_val("PWD", en);
	printf("%s\n", pwd);
	free(pwd);
	g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
}
