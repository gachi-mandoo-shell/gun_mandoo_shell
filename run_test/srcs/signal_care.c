
#include "minishell.h"

void	*signal_ctlc(int	signo)
{
	// printf("\n[%d]\n",WIFSIGNALED(exit_code));
	printf("\n[%d]\n",g_ex.pid);
	g_ex.is_signaled = -1;
	if (g_ex.pid == 0)
		write(1, "\b\b\nminishell test> ", ft_strlen("  \nminishell test>>"));
	else if (g_ex.pid > 0)
		write(1, "\b\b  ", ft_strlen("\b\b  "));
	return (0);
}

// void	*signal_ctld(int	signo)
// {
// 	printf("\n\nWow!! ctl + D !!  HOHOHOHOHOHOHOHOHOHOHOOO!!!!!!!\n\n");
// 	// if (exit_code == 0)
// 	// 	write(1, "\b\b  \nminishell !!!!> ", ft_strlen("\b\b  \nminishell test> "));
// 	return (0);
// }

void	*signal_ctlslash(int	signo)
{

	// if ((g_ex.exit_code != 131 && g_ex.is_signaled != 0) || (g_ex.is_signaled == -1))
	if (g_ex.pid > 0)
	{
		write(1, "Quit: 3\nminishell test> ", ft_strlen("Quit: 3\nminishell test>>"));
	}
	//ex.is_signaled = -1;
	// write(1, "\b    \nminishell test> ", ft_strlen("      \nminishell test>>"));
	return (0);
}

// void	*signal_child_ctld(int	signo)
// {
// 	printf("\n\nWow!! ctl D !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
// 	return (0);
// }

// void	*signal_child_ctlslash(int	signo)
// {
// 	printf("\n\nWow!! ctl + \\ !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
// 	return (0);
// }

// void	*signal_child_ctlc(int signo)
// {
// 	printf("\n!!!!!!!\n");
// 	exit(0);
// }