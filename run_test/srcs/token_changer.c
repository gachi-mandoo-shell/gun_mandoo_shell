#include "minishell.h"

int	env_changer(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		k;
	int		cpy_i;

	ft_memset(key_tmp, 0, PATH_MAX);
	k = 0;
	if (!args[(*arg_i) + 1])
	{
		ft_strcat(cpy_arg, "$");
		return (1);
	}
	if (args[(*arg_i) + 1] == '?')
	{
		(*arg_i)++;
		key_val = ft_itoa(g_ex.exit_code);
		ft_strcat(cpy_arg, key_val);
		cpy_i = ft_strlen(key_val);
		free(key_val);
		return (cpy_i);
	}

	while (!ft_strchr(" \t\n\r\a\"\'$", args[++(*arg_i)]))
		key_tmp[k++] = args[(*arg_i)];
	if (ft_strchr("\'\"$", args[(*arg_i)]))
		(*arg_i)--;
	cpy_i = 0;
	key_val = find_env_val(key_tmp, *en);
	if (key_val)
	{
		ft_strcat(cpy_arg, key_val);
		cpy_i = ft_strlen(key_val);
		free(key_val);
	}
	return (cpy_i);
}

int	env_except_qoute(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	if ((args[(*arg_i) + 1] == '\'') || (args[(*arg_i) + 1] == '\"') || (args[(*arg_i) + 1] == '$'))
	{
		ft_strcat(cpy_arg, "$");
		return (1);
	}
	else
		return (env_changer(args, arg_i, cpy_arg, en));
}

int	env_except_none(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	if ((args[(*arg_i) + 1] == '\'') || (args[(*arg_i) + 1] == '\"') || (args[(*arg_i) + 1] == '$'))
		return (0);
	else
		return (env_changer(args, arg_i, cpy_arg, en));
}

char	*env_controller(char *args, char ***en)
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
					cpy_i += env_except_qoute(args, \
					&arg_i, cpy_arg + cpy_i, en);
				else
					cpy_arg[cpy_i++] = args[arg_i];
			}
		}
		if (!ft_strchr("\'\"$", args[arg_i]))
			cpy_arg[cpy_i++] = args[arg_i];
		if (args[arg_i] == '$')
			cpy_i += env_except_none(args, \
			&arg_i, cpy_arg + cpy_i, en);
	}
	return (ft_strdup(cpy_arg));
}

int	token_changer(t_nd *nd, char ***en)
{
	char	*tmp;
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
			break ;
	}
	return (EXIT_SUCCESS);
}
