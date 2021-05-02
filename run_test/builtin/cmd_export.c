#include "minishell.h"

char	**add_env(char ***en, char *str)
{
	char	**new_en;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 2));
	if (!new_en)
		return (0);
	while ((*en)[++i])
	{
		new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free((*en)[i]);
	new_en[++j] = ft_strdup(str);
	new_en[++j] = 0;
	return (new_en);
}

char	**update_env(char ***en, char *str, char *find_en)
{
	char	**new_en;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 1));
	if (!new_en)
		return (0);
	while ((*en)[++i])
	{
		if (find_en == (*en)[i])
			new_en[++j] = ft_strdup(str);
		else
			new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free((*en)[i]);
	new_en[++j] = 0;
	return (new_en);
}

char	*check_equal(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			break;
	}
	if (i == 0 || str[i] == 0)
		return (0);
	else
		return (ft_strndup(str, i));
}

int	export_print(t_nd *com, char ***en, char *av)
{
	int	i;

	i = -1;
	while ((* en)[++i])
	{
		printf("declare -x ");
		printf("%s\n", (* en)[i]);
	}
	return (EXIT_SUCCESS);
}

int	cmd_export(t_nd *com, char ***en, char *av)
{
	char *tmp;
	char *tmp2;
	char **new_en;
	int i;
	int	j;

	i = -1;
	j = -1;
	if (!com->args[1]) 
		export_print(com, en, av);
	else
	{
		tmp2 = check_equal(com->args[1]);
		// printf("\n\n==> %s\n\n",tmp);
		if (!tmp2)
		{
			printf("minishell: export: not a valid identifier");
			return (EXIT_SUCCESS);
		}
		tmp = find_env(tmp2, *en);
		free(tmp2);
		// if (!tmp)
		// {
		// 	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 2));
		// 	if (!new_en)
		// 		return (EXIT_FAILURE);
		// 	while ((*en)[++i])
		// 	{
		// 		new_en[++j] = ft_strdup((*en)[i]);
		// 		free((*en)[i]);
		// 	}
		// 	free((*en)[i]);
		// 	new_en[++j] = ft_strdup(com->args[1]);
		// 	new_en[++j] = 0;
		// }
		// else
		// {
		// 	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 1));
		// 	if (!new_en)
		// 		return (EXIT_FAILURE);
		// 	while ((*en)[++i])
		// 	{
		// 		if (tmp == (*en)[i])
		// 			new_en[++j] = ft_strdup(com->args[1]);
		// 		else
		// 			new_en[++j] = ft_strdup((*en)[i]);
		// 		free((*en)[i]);
		// 	}
		// 	free((*en)[i]);
		// 	new_en[++j] = 0;
		// }
		if (!tmp)
			new_en = add_env(en, com->args[1]);
		else
			new_en = update_env(en, com->args[1], tmp);
		(*en) = new_en;
	}
	return(EXIT_SUCCESS);
}