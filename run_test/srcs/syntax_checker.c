#include "minishell.h"

int	find_file_name(char *arg)
{
	int	i;

	i = 1;
	while (arg[i] && ft_strchr(SEP, arg[i]))
		i++;
	if (arg[i] == '>' || arg[i] == '<' || !arg[i])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	synerror_redirect(char *arg)
{
	int	qq_f;
	int	q_f;
	int	i;

	qq_f = 1;
	q_f = 1;
	i = -1;
	if (!arg || !*arg)
		return (EXIT_SUCCESS);
	while (arg[++i])
	{
		if (arg[i] == '\'')
			q_f *= -1;
		else if (arg[i] == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			if (arg[i + 1] == '>')
				i++;
			if (find_file_name(&arg[i]) == EXIT_FAILURE)
			{
				g_ex.exit_code = 258;
				printf("redirection : syntax error\n");
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	synerror_checker(char *args, char a)
{
	int		len;
	int		i;
	int		q_f;
	int		qq_f;

	q_f = 1;
	qq_f = 1;
	i = 0;
	if (!args)
		return (EXIT_SUCCESS);
	while (args[i] && ft_strchr(SEP, args[i]))
		i++;
	if (args[i] == a)
	{
		printf("%c : syntax error\n", a);
		return (-1);
	}
	i = -1;
	while (args[++i])
	{
		if (args[i] == '\"')
			qq_f *= -1;
		else if (args[i] == '\'')
			q_f *= -1;
		else if ((args[i] == a) && qq_f > 0 && q_f > 0)
		{
			i++;
			while (args[i] == ' ')
				i++;
			if (args[i] == a || (!args[i] && a == '|'))
			{
				printf("%c : syntax error\n", a);
				g_ex.exit_code = 258;
				return (-1);
			}
		}
	}
	if (qq_f == -1 || q_f == -1)
	{
		printf("minishell : quote error\n");
		g_ex.exit_code = 258;
		return (-1);
	}
	return (EXIT_SUCCESS);
}
