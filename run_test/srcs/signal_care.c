
#include "minishell.h"

void	*signal_ctlc(int	signo)
{
	printf("\b\b  \n");
	return (0);
}

void	*signal_ctld(int	signo)
{
	printf("\n\nWow!! ctl D !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
	return (0);
}

void	*signal_ctlslash(int	signo)
{
	printf("\n\nWow!! ctl + \\ !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
	return (0);
}

void	*signal_child_ctlc(int	signo)
{
	printf("\b\b  \n");
	exit(EXIT_SUCCESS);
}

void	*signal_child_ctld(int	signo)
{
	printf("\n\nWow!! ctl D !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
	return (0);
}

void	*signal_child_ctlslash(int	signo)
{
	printf("\n\nWow!! ctl + \\ !!  YEEEEEEEEEEEEHA!!!!!!!\n\n");
	return (0);
}