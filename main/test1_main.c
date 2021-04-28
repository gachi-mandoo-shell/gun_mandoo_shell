#include "test.h"

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

	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // non-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	init_env(&env, en);
	rt = start_shell(env, av[0]);
}