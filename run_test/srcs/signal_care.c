#include "minishell.h"

void	*signal_ctlc(int signo)
{
	if (g_ex.pid == 0)
		write(1, "\b\b\ngun_mandoo_shell > ", ft_strlen("\b\b\ngun_mandoo_shell > "));
	else if (g_ex.pid > 0)
		printf("\n");
	return (0);
}

// void	*signal_ctld(int signo)
// {
// 	printf("%d\n", g_ex.pid);
// 	if (g_ex.pid == 0)
// 	{
// 		printf("exit\n");
// 		exit(0);
// 	}
// 	return (0);
// }

void	*signal_ctlslash(int signo)
{
	if (g_ex.pid > 0)
		write(1, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	return (0);
}
