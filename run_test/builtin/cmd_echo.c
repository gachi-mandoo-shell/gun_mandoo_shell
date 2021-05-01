#include "minishell.h"

// 초기형
int		cmd_echo(t_nd *com, char ***en, char *av)
{
	int		i;
	int		is_n;

	i = 0;
	is_n = 0;
	if (!com->args[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	if (!strcmp(com->args[1], "-n"))
	{
		i = 1;
		is_n = -1;
	}
	while (com->args[++i])
	{
		write(1, com->args[i], ft_strlen(com->args[i]));
		if (com->args[i + 1])
			write(1, " ", 1);
	}
	
	
	// 스플릿쿼트랑 이엔브이컨트롤러 보기
	

	if (is_n != -1)
		printf("\n");
	return (EXIT_SUCCESS);
}
