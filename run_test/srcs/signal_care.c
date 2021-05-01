
#include "minishell.h"

void	*signal_ctlc(int	signo)
{
	// if (exit_code != 130)
		write(1, "\b\b  \nminishell test>  ", ft_strlen("\b\b  \nminishell test>   "));
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
	// if (exit_code != 131)
		write(1, "\b\b  \nminishell test> ", ft_strlen("\b\b  \nminishell test> "));
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