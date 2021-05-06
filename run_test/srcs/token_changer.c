/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:24 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 02:17:13 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(int *cpy_i, int *arg_i, char (*cpy_arg)[PATH_MAX])
{
	*arg_i = -1;
	*cpy_i = 0;
	ft_memset(cpy_arg, 0, PATH_MAX);
}

void	env_controller_2(int *bs_f, int *arg, \
							char cpy_arg[PATH_MAX], char *args)
{
	*bs_f = 1;
	if (*bs_f > 0 && args[arg[0]] == '\\')
	{
		*bs_f *= -1;
		arg[0]++;
	}
	if (*bs_f > 0 && args[arg[0]] == '\'')
		while (args[++arg[0]] != '\'')
			cpy_arg[arg[1]++] = args[arg[0]];
}

int		jg(char c)
{
	if (c == '`' || c == '\\' || c == '\"' || c == '$')
		return (1);
	else
		return (0);
}

char	*env_controller(char *args, char ***en)
{
	char	cpy_arg[PATH_MAX];
	int		arg[2];
	int		bs_f;

	env_init(&arg[1], &arg[0], &cpy_arg);
	while (args[++arg[0]])
	{
		env_controller_2(&bs_f, arg, cpy_arg, args);
		if (bs_f > 0 && args[arg[0]] == '\"')
		{
			while (bs_f > 0 && args[arg[0]] == '\"' && !(args[++arg[0]] == '\"'))
				if (args[arg[0]] == '$')
					arg[1] += env_except_qoute(args, &arg[0], cpy_arg + arg[1], en);
				else if (args[arg[0]] == '\\' && ft_strchr("`\\\"$", args[arg[0] + 1]))
					cpy_arg[arg[1]++] = args[++arg[0]];
				else
					cpy_arg[arg[1]++] = args[arg[0]];
		}
		if (!ft_strchr("\'\"$", args[arg[0]]) || bs_f < 0)
			cpy_arg[arg[1]++] = args[arg[0]];
		if (bs_f > 0 && args[arg[0]] == '$')
			arg[1] += env_except_none(args, &arg[0], cpy_arg + arg[1], en);
	}
	return (ft_strdup(cpy_arg));
}

int		token_changer(t_nd *nd, char ***en)
{
	char	*tmp;
	int		arg_count;

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
