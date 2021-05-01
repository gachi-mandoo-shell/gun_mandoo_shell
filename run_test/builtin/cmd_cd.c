
#include "minishell.h"

int		cmd_cd(t_nd *com, char ***en, char *av)
{
	char	tmp[PATH_MAX];
	char	**new_en;
	char	*tmp2;
	char	*new_key;
	char	*oldpwd_key;
	char	*oldpwd_val;
	char	*old;
	char	*new;
	int		rt;

	old = ft_strjoin("OLDPWD=", getcwd(tmp, PATH_MAX));
	ft_memset(tmp, 0, PATH_MAX);
	oldpwd_key = find_env("OLDPWD", *en);
	oldpwd_val = find_env_val("OLDPWD", *en);
	if ((com->args[1]) && !strcmp(com->args[1], "~"))
		rt = chdir(getenv("HOME"));
	if ((com->args[1]) && !strcmp(com->args[1], "-"))
	{
		if (!oldpwd_key)
			rt = -1;
		else
			rt = chdir(oldpwd_val);
	}
	else if (!com->args[1])
	{
		rt = chdir(find_env_val("HOME", *en));
		rt = -2;
	} 
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
		if (rt == -1)
			printf("minishell: %s: OLDPWD not set\n", com->args[0]);
		else if (rt == -2)
			printf("minishell: %s: HOME not set\n", com->args[0]);
		else
			printf("%s: %s: %s\n",com->args[0], com->args[1], strerror(errno));
	}
	else
	{
		new = ft_strjoin("PWD=", getcwd(tmp, PATH_MAX));
		if (!oldpwd_key)
			new_en = add_env(en, old);
		else
			new_en = update_env(en, old, oldpwd_key);
		(*en) = new_en;
		new_key = find_env("PWD", *en);
		new_en = update_env(en, new, new_key);
		(*en) = new_en;
	}
	return (EXIT_SUCCESS);
}

