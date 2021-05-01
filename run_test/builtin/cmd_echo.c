#include "minishell.h"

// 초기형
int		cmd_echo(t_nd *com, char ***en, char *av)
{
	int		i;
	int		j;
	int		is_n;

	i = 0;
	is_n = 0;
	if (!com->args[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	j = 0;
	if (com->args[1][j] == '-')
	{
		j++;
		while (com->args[1][j] == 'n')
			j++;
		if (!(j == 1 || com->args[1][j]))
		{
			is_n = -1;
			i++;
		}
	}
	while (com->args[++i])
	{
		write(1, com->args[i], ft_strlen(com->args[i]));
		if (com->args[i + 1])
			write(1, " ", 1);
	}
	if (is_n != -1)
		printf("\n");
	return (EXIT_SUCCESS);
}
