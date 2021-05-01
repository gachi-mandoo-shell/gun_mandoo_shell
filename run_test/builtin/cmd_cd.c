
#include "minishell.h"

int		cmd_cd(t_nd *com, char ***en, char *av)
{
	char	tmp[PATH_MAX];
	char	*tmp2;
	int		rt;

	getcwd(tmp, PATH_MAX);
	printf("\n-> %s\n", tmp);

	if ((com->args[1]) && !strcmp(com->args[1], "~"))
		rt = chdir(getenv("HOME"));
	else if (!com->args[1])
	{
		rt = chdir(find_env_val("HOME", *en));
		rt = -2;
	} 
		
		// unset으로 환경변수를 없앤 후에 어떻게 동작하는지 확인해볼것


	else if (com->args[1][0] == '~')
	{
		tmp2 = ft_strjoin(getenv("HOME"), com->args[1] + 1);
		rt = chdir(tmp2);
		free(tmp2);
	}
	else
		rt = chdir(com->args[1]);

	if (rt < 0)
	{
		if (rt == -2)
			printf("%s: %s: HOME not set\n", com->args[0], com->args[1]);
		else
			printf("%s: %s: %s\n",com->args[0], com->args[1], strerror(errno));
	}
	// else
	// {
	// 	// 환경변수에 추가해주는 함수 작업필요
	// 	ft_export(OLDPWD, tmp);
	// 	getcwd(tmp, 1024);
	// 	ft_export(PWD, tmp);
	// }
	return (EXIT_SUCCESS);
}

