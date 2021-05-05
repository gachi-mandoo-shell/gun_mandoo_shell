
#include "minishell.h"

void	cmd_cd_new(char **oldpwd_key, char **old, char ***en)
{
	char tmp[PATH_MAX];
	char	**new_en;
	char	*new;
	char	*new_key;

	new = ft_strjoin("PWD=", getcwd(tmp, PATH_MAX));
	if (!*oldpwd_key)
		new_en = add_env(en, *old);
	else
		new_en = update_env(en, *old, *oldpwd_key);
	(*en) = new_en;
	new_key = find_env("PWD", en);
	new_en = update_env(en, new, new_key);
	(*en) = new_en;
	g_ex.exit_code = 0;
}

void	cmd_cd_old(char **oldpwd_key, char **oldpwd_val, char **old, char ***en)
{
	(*oldpwd_val) = find_env_val("PWD", en);
	(*old) = ft_strjoin("OLDPWD=", (*oldpwd_val));
	free(oldpwd_val);
	(*oldpwd_key) = find_env("OLDPWD", en);
	(*oldpwd_val) = find_env_val("OLDPWD", en);
}

int		cmd_cd_2(t_nd *com, char **oldpwd_key, char **oldpwd_val, char ***en)
{
	char	*tmp2;
	int		rt;
	char	tmp[PATH_MAX];
	char	*a;

	if ((com->args[1]) && !ft_strcmp(com->args[1], "-"))
	{
		if (!oldpwd_key)
			rt = -2;
		else
			rt = chdir(*oldpwd_val);
	}
	else if (!com->args[1])
	{
		rt = chdir(find_env_val("HOME", en));
		if (rt < 0)
			rt = -3;
	}
	else if (com->args[1][0] == '~')
	{
		tmp2 = ft_strjoin(getenv("HOME"), com->args[1] + 1);
		rt = chdir(tmp2);
		free(tmp2);
	}
	else
		rt = chdir(com->args[1]);
	return (rt);
}

int		cmd_cd(t_nd *com, char ***en, char *av)
{
	char	tmp[PATH_MAX];
	char	*oldpwd_key;
	char	*oldpwd_val;
	char	*old;
	int		rt;

	if (!getcwd(tmp, PATH_MAX))
	{
		chdir(com->args[1]);
		if (!getcwd(tmp, PATH_MAX))
		{
			printf("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n");
			return (EXIT_SUCCESS);
		}
	}
	else
		rt = cmd_cd_2(com, &oldpwd_key, &oldpwd_val, en);
	if (rt < 0)
	{
		if (rt == -2)
			printf("minishell: %s: OLDPWD not set\n", com->args[0]);
		else if (rt == -3)
			printf("minishell: %s: HOME not set\n", com->args[0]);
		else
			printf("%s: %s: %s\n", com->args[0], com->args[1], strerror(errno));
		g_ex.exit_code = 1;
	}
	oldpwd_val = find_env_val("PWD", en);
	old = ft_strjoin("OLDPWD=", oldpwd_val);
	free(oldpwd_val);
	oldpwd_key = find_env("OLDPWD", en);
	oldpwd_val = find_env_val("OLDPWD", en);
	//cmd_cd_old(&oldpwd_key, &oldpwd_val, &old, en);
	cmd_cd_new(&oldpwd_key, &old, en);
	return (EXIT_SUCCESS);
}
