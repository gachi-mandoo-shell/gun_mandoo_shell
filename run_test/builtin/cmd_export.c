#include "minishell.h"

void	get_key_val(char *str, char **key, char **value)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			break ;
	}
	(*key) = ft_strndup(str, i);
	if (!str[i])
		(*value) = 0;
	else
		(*value) = ft_strdup(str + i + 1);
}

char	*check_equal(char *str, char **key, char **value, char *name)
{
	get_key_val(str, key, value);
	if (!(*key)[0] || ft_isdigit((*key)[0]))
	{
		free(*key);
		if (*value)
			free(*value);
		printf("minishell: export: `%s': not a valid identifier\n", name);
		g_ex.exit_code = -1;
		return (0);
	}
	return (*key);
}

void	trans_env(char **en)
{
	int		i;
	int		j;
	int		num;
	int		min;
	char	*tmp;

	num = matrix_line_num(en);
	i = -1;
	j = -1;
	min = 0;
	while (++i < num)
	{
		j = i;
		min = i;
		while (++j < num)
		{
			if (ft_strcmp(en[i], en[j]) >= 0)
			{
				tmp = ft_strdup(en[i]);
				free(en[i]);
				en[i] = ft_strdup(en[j]);
				free(en[j]);
				en[j] = ft_strdup(tmp);
				free(tmp);
			}
		}
	}
}

int	export_print(t_nd *com, char **en, char *av)
{
	int		i;
	int		j;
	char	**tmp_en;

	i = -1;
	tmp_en = malloc(sizeof(char*) * (matrix_line_num(en) + 1));
	if (!tmp_en)
		return (0);
	while (++i < matrix_line_num(en))
		tmp_en[i] = ft_strdup(en[i]);
	tmp_en[i] = 0;
	i = -1;
	trans_env(tmp_en);
	while (en[++i])
	{
		j = -1;
		printf("declare -x ");
		while (tmp_en[i][++j])
		{
			printf("%c", tmp_en[i][j]);
			if (tmp_en[i][j] == '=')
				printf("\"");
		}
		printf("\"\n");
		free(tmp_en[i]);
	}
	free(tmp_en);
	return (EXIT_SUCCESS);
}

int	cmd_export(t_nd *com, char ***en, char *av)
{
	char	*tmp;
	char	**new_en;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	if (!com->args[1])
	{
		export_print(com, *en, av);
		return (EXIT_SUCCESS);
	}
	while (com->args[++i])
	{
		if (check_equal(com->args[i], &key, &value, com->args[i]) && value)
		{
			tmp = find_env(key, en);
			if (!tmp)
				new_en = add_env(en, com->args[i]);
			else
				new_en = update_env(en, com->args[i], tmp);
			free(key);
			free(value);
			(*en) = new_en;
		}
	}
	if (g_ex.exit_code < 0)
		g_ex.exit_code = 1;
	else
		g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
}
