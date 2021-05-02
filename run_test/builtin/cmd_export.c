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

int	export_print(t_nd *com, char ***en, char *av)
{
	int	i;

	i = -1;
	while ((*en)[++i])
	{
		printf("declare -x ");
		printf("%s\n", (*en)[i]);
	}
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
		export_print(com, en, av);
		return (EXIT_SUCCESS);
	}
	while (com->args[++i])
	{
		if (check_equal(com->args[i], &key, &value, com->args[i]) && value)
		{
			tmp = find_env(key, *en);
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
