
#include "minishell.h"

int		cmd_cd(char **run_com, char **en, char *av)
{
	char	tmp[PATH_MAX];
	char	*tmp2;
	int				rt;

	getcwd(tmp, PATH_MAX);
	rt = ft_strncmp(run_com[1], "~", ft_strlen(run_com[1]));
	if (rt == 0 || !run_com[1])
		rt = chdir(find_env_val("HOME", en));
	// 예외 처리에 대해 더 연구하고 좀 더 정확하게 수정할 것
	else if (ft_strnstr(run_com[1], tmp, ft_strlen(tmp)))
	{
		rt = chdir(run_com[1]);
	}
	else
	{
		if (run_com[1][0] == '.' && run_com[1][1] == '/')
			rt = chdir(run_com[1]);
		else
		{
			tmp2 = ft_strjoin("./", run_com[1]);
			rt = chdir(tmp2);
			free(tmp2);
		}
	}

	if (rt < 0)
		printf("%s: %s: %s\n",run_com[0], run_com[1], strerror(errno));
	// else
	// {
	// 	// 환경변수에 추가해주는 함수 작업필요
	// 	ft_export(OLDPWD, tmp);
	// 	getcwd(tmp, 1024);
	// 	ft_export(PWD, tmp);
	// }
	return (1);
}

