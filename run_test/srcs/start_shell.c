#include "minishell.h"

void	start_write(void)
{
	printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░░▒▒▒▒░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░▒▒▒░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░▓▓\n");
	printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
	printf("_______▒__________▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
	printf("______▒_______________▒▒▒▒▒▒▒▒\n");
	printf("_____▒________________▒▒▒▒▒▒▒▒\n");
	printf("____▒___________▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
	printf("___▒\n");
	printf("__▒______▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
	printf("_▒______▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓\n");
	printf("▒▒▒▒___▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓\n");
	printf("▒▒▒▒__▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓\n");
	printf("▒▒▒__▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
	printf("▒▒\n");

}

char	*read_line(void)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	return (line);
}

int		run_cmd(t_nd *coms, char **en, char *av)
{
	t_nd	*anc;
	int		rt;
	int		i;

	i = -1;
	rt = EXIT_SUCCESS;
	anc = coms;
	while (coms)
	{
		if(lexer(coms, coms->args[0]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (tokenizer(coms->child) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (coms->sible)
			coms = coms->sible;
		else
			break ;
	}
	while (anc && rt == EXIT_SUCCESS)
	{
		token_changer(anc->child, en);
		get_redirect(anc->child, en);
		rt = run(anc->child, en, av);
		if (anc->sible)
			anc = anc->sible;
		else
			break ;
	}
	return (rt);
}


int		start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	char	hist[PATH_MAX][PATH_MAX];
	t_nd	*coms;
	// int		i;
	// i = -1;
	// while (++i < PATH_MAX)
	// 	ft_memset(hist[i], 0, PATH_MAX);
	status = EXIT_SUCCESS;
	start_write();
	// i = 0;

	// signal(SIGINT, SIG_IGN);
	// signal(SIGINT, (void*)signal_ctlc);
	// signal(SIGTERM, (void*)signal_ctld);
	// signal(SIGQUIT, (void*)signal_ctlslash);
	while (status == EXIT_SUCCESS)
	{

		write(1, "minishell test>!! ", ft_strlen("minishell test>!! "));
		line = read_line();
		//line = ft_strdup("");
		if (synerror_checker(line, ';') >= 0)
		{
			coms = big_cutter(line);
			free(line);
			status = run_cmd(coms->child, en, av);
		}
		// printf("status : %d\n", status);
	}
	return (0);
}
