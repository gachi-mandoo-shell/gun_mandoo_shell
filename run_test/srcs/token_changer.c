#include "minishell.h"

int	env_changer(char *args, int *arg_i, char *cpy_arg, char **en)
{
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		k;
	int		cpy_i;

	ft_memset(key_tmp, 0, PATH_MAX);
	k = 0;
	while (!ft_strchr(" \t\n\r\a\"\'$", args[++(*arg_i)]))
		key_tmp[k++] = args[(*arg_i)];
	key_val = find_env_val(key_tmp, en);
	strcat(cpy_arg, key_val);
	cpy_i = ft_strlen(key_val);
	free(key_val);
	return (cpy_i);
}

char	*env_controller(char *args, char **en)
{
	char	cpy_arg[PATH_MAX];
	int		cpy_i;
	int		arg_i;

	arg_i = -1;
	cpy_i = 0;
	ft_memset(cpy_arg, 0, PATH_MAX);
	while (args[++arg_i])
	{
		if (args[arg_i] == '\'')
			while (args[++arg_i] != '\'')
				cpy_arg[cpy_i++] = args[arg_i];
		if (args[arg_i] == '\"')
		{
			while (args[++arg_i] != '\"')
			{
				if (args[arg_i] == '$')
					cpy_i += env_changer(args, \
					&arg_i, cpy_arg + cpy_i, en);
				cpy_arg[cpy_i++] = args[arg_i];
			}
		}
		if (args[arg_i] == '$')
			cpy_i += env_changer(args, \
			&arg_i, cpy_arg + cpy_i, en);
		if (!ft_strchr("\'\"$", args[arg_i]))
			cpy_arg[cpy_i++] = args[arg_i];
	}
	return (ft_strdup(cpy_arg));
}

// int		call_env(t_nd *nd, char **en)
// {
// 	char 	*tmp;
// 	int		arg_count;

// 	arg_count = -1;
// 	while (nd->args[++arg_count])
// 	{
// 		tmp = env_controller(nd->args[arg_count], en);
// 		free(nd->args[arg_count]);
// 		nd->args[arg_count] = ft_strdup(tmp);
// 		free(tmp);
// 	}
// 	return (EXIT_SUCCESS);
// }

int	token_changer(t_nd *nd, char **en)
{
	char 	*tmp;
	int		arg_count;
	t_nd	*anc;

	while (nd)
	{
		arg_count = -1;
		while (nd->args[++arg_count])
		{
			tmp = env_controller(nd->args[arg_count], en);
			free(nd->args[arg_count]);
			nd->args[arg_count] = ft_strdup(tmp);
			free(tmp);
		}
		if (nd->sible)
			nd = nd->sible;
		else
			break;
	}
	return (EXIT_SUCCESS);
}
