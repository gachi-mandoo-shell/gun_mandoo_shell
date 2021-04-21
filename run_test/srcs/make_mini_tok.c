#include "minishell.h"

int	env_changer(char *args, int *arg_i, char *cpy_arg, char **en)
{
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		k;
	int		cpy_i;

	arg_i = 0;
	cpy_i = 0;
	ft_memset(key_tmp, 0, PATH_MAX);
	k = 0;
	while (!ft_strchr(" \t\n\r\a\"\'$", args[++(*arg_i)]))
		key_tmp[k++] = args[(*arg_i)];
	key_val = find_env_val(key_tmp, en);
	strcat(cpy_arg, key_val);
	cpy_i += ft_strlen(key_val);
	free(key_val);
	return (cpy_i);
}

int	env_controller(t_nd *nd, char **en)
{
	char	cpy_arg[PATH_MAX];
	int		cpy_i;
	int		arg_i;
	int		arg_count;

	arg_count = -1;
	while (nd->args[++arg_count])
	{
		arg_i = -1;
		cpy_i = 0;
		ft_memset(cpy_arg, 0, PATH_MAX);
		while (nd->args[arg_count][++arg_i])
		{
			if (nd->args[arg_count][arg_i] == '\'')
				while (nd->args[arg_count][++arg_i] == '\'')
					cpy_arg[cpy_i++] = nd->args[arg_count][arg_i];
			if (nd->args[arg_count][arg_i] == '\"')
			{
				while (nd->args[arg_count][++arg_i] == '\"')
				{
					if (nd->args[arg_count][arg_i] == '$')
						cpy_i += env_changer(nd->args[arg_count], \
						&arg_i, cpy_arg + cpy_i, en);
					cpy_arg[cpy_i++] = nd->args[arg_count][arg_i];
				}
			}
			if (nd->args[arg_count][arg_i] == '$')
				cpy_i += env_changer(nd->args[arg_count], \
				&arg_i, cpy_arg + cpy_i, en);
			if (!ft_strchr("\'\"$", nd->args[arg_count][arg_i]))
				cpy_arg[cpy_i++] = nd->args[arg_count][arg_i];
		}
		nd->args[arg_count] = ft_strdup(cpy_arg);
	}
	return (EXIT_SUCCESS);
}

int		make_mini_tok(t_nd *nd)
{
	char	*tmp;
	t_nd	*tmp_nd;
	int		i;

	i = -1;
	tmp_nd = nd;
	while (nd)
	{
		tmp = ft_strdup(tmp_nd->args[0]);
		free(tmp_nd->args[0]);
		free(tmp_nd->args);
		tmp_nd->args = split_qoute(tmp, SEP);
		free(tmp);
		if (tmp_nd->sible)
			tmp_nd = tmp_nd->sible;
		else 
			break;
	}
	// env_changer(nd);
	return (EXIT_SUCCESS);
}
