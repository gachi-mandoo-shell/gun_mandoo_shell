#include "minishell.h"


// int		env_changer(t_nd *nd)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		qq_f;
// 	int		q_f;
// 	char	key_tmp[PATH_MAX];

// 	qq_f = 1;
// 	q_f = 1;
// 	i = -1;
// 	k = 0;
// 	while(nd->args[++i])
// 	{
// 		j = -1;
// 		while (nd->args[i][++j])
// 		{
// 			if (nd->args[i][j] == '\'')
// 				q_f *= -1;
// 			else if (nd->args[i][j] == '\"')
// 				qq_f *= -1;
// 			if (q_f > 0 && (nd->args[i][j] == '$'))
// 			{
// 				while(!ft_strchr(" \t\n\r\a\"\'$", nd->args[i][++j]))
// 					key_tmp[k++] = nd_args[i][j];
// 				key_tmp[k] = 0;

// 			}
// 			else if

// 		}
// 	}
// }

int		env_changer(t_nd *nd)
{
	char	cpy_arg[PATH_MAX];
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		cpy_i;
	int		arg_i;
	int		arg_count;

	arg_count = -1;
	ft_memset(cpy_arg, 0, PATH_MAX);
	while (nd->args[++arg_count])
	{
		arg_i = -1;
		cpy_i = 0;
		while (nd->nd_args[arg_count][++arg_i])
		{
			if (nd->args[arg_count][arg_i] == '\'')
			{
				while (nd->args[arg_count][++arg_i] == '\'')
					cpy_arg[cpy_i++] = nd->args[arg_count][arg_i];
			}
			if (nd->args[arg_count][arg_i] == '\"')
			{
				while (nd->args[arg_count][++arg_i] == '\"')
				{
					if (nd->args[arg_count][arg_i] == '$')
					{
						while (!ft_strchr(" \t\n\r\a\"\'$", nd->args[arg_count][++arg_i]))
							key_tmp[k++] = nd->args[arg_count][arg_i];
						key_tmp[k++] = 0;
						key_val = find_env_val(key_tmp, en);
						strcat(cpy_arg, key_val);
						cpy_i += ft_strlen(key_val);
						free(key_val);
					}
					if (nd->args[arg_count][arg_i] != "\"")
						cpy_arg[cpy_i++] = nd->args[arg_count][arg_i];
				}
			}
			if (nd->args[arg_count][arg_i] == '$')
			{
				while (!ft_strchr(" \t\n\r\a\"\'$", nd->args[arg_count][++arg_i]))
					key_tmp[k++] = nd->args[arg_count][arg_i];
				key_tmp[k++] = 0;
				key_val = find_env_val(key_tmp, en);
				strcat(cpy_arg, key_val);
				cpy_i += ft_strlen(key_val);
				free(key_val);
				arg_i--;
			}
		}
	}
}

char	**make_mini_tok(t_nd *nd)
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
	env_changer(nd);

}
