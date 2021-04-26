
#include "minishell.h"

void	*signal_ctlc(int	signo)
{
	pid_t pid;

	pid = getpid();
	if (pid != 0)
		write(1, "\b\b  \nminishell test> ", ft_strlen("\b\b  \nminishell test> "));
	if (pid == 0)
		exit(0);
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

void	*signal_child_ctlc(int signo, pid_t pid)
{
	exit(pid);
}