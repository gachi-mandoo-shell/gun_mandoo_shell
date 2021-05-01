#include "minishell.h"

void	init_env(char ***env, char *en[])
{
	int		i;
	int		j;

	i = 0;
	while (en[i])
		i++;
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	(*env)[i] = 0;
	j = -1;
	while (++j < i)
		(*env)[j] = ft_strdup(en[j]);
}

int		main(int ac, char *av[], char *en[])
{
	char	**env;
	char	rt;
	// struct termios term;

	//===============================

	// tcgetattr(STDIN_FILENO, &term);
	// term.c_lflag &= ~ICANON;    
	// term.c_lflag &= ~ECHO;      
	// term.c_cc[VMIN] = 1; 
	// term.c_cc[VTIME] = 0;
	// tcsetattr(STDIN_FILENO, TCSANOW, &term);
	//===============================

	exit_code = 0;
	init_env(&env, en);
	rt = start_shell(&env, av[0]);
}
