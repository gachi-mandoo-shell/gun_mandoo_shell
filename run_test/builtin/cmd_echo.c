#include "minishell.h"

int		cmd_echo_2(t_nd *com, char ***en, char *av)
{
	int		i;
	int		j;
	int		is_n;

	j = 0;
	i = 0;
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
	return (is_n);
}

int		cmd_echo(t_nd *com, char ***en, char *av)
{
	int		is_n;

	if (!com->args[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	is_n = cmd_echo_2(com, en, av);
	if (is_n != -1)
		printf("\n");
	g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
}
