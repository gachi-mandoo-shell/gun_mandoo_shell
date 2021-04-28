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
			return (EXIT_SUCCESS);
		if (tokenizer(coms->child) == EXIT_FAILURE)
			return (EXIT_SUCCESS);
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

int	line_check(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_strchr(SEP, line[i]))
		i++;
	if (!line[i])
		return (0);
	return (1);
}

void	delete_char(int size)
{
	char	alt[size * 2];
	int 	i;

	i = -1;
	printf("%d\n", size);
	while (++i < size)
		alt[i] = '\b';
	while (i < size * 2)
		alt[i++] = ' ';
	write(1, alt, size * 2);
	write(1, alt, size);
}

char	*get_ch(t_hist	**nd)
{
	char	c[2];
	char	*tmp;
	struct termios term;
	struct termios back;
	t_hist	*tmp_his;


	c[1] = 0;

	tcgetattr(STDIN_FILENO, &term);
	tcgetattr(STDIN_FILENO, &back);
	term.c_lflag &= ~ICANON;    
	term.c_lflag &= ~ECHO;      
	term.c_cc[VMIN] = 1; 
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	while (read(0, c, 1) > 0)
	{
		if ((int)c[0] == 27)
		{
			read(0, c, 1);
			if ((int)c[0] == 91)
			{
				read(0, c, 1);
				if ((int)c[0] == 65)
				{
					if ((*nd)->content)
						delete_char(ft_strlen((*nd)->content));
					if ((*nd)->prev)
					{
						write(1, (*nd)->prev->content, ft_strlen((*nd)->prev->content));
						(*nd) = (*nd)->prev;	
					}
				}
			}
		}
		else
		{
			write(1, c, 1);
			if (c[0] == '\n')
				break ;
			if (!(*nd)->content)
				(*nd)->content = ft_strdup(c);
			else
			{
				c[1] = 0;
				tmp = (*nd)->content;
				(*nd)->content = ft_strjoin(tmp, c);
				free(tmp);
			}
			// delete_char(nd, ft_strlen(nd->content));
			// write(1, nd->content, ft_strlen(nd->content));
		}
		// delete_char(nd, ft_strlen(nd->content));
		// write(1, nd->content, ft_strlen(nd->content));
		//printf("\n[[%s]]\n", nd->content);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &back);
	// printf("\n\n\n\n");
	// print_list_2(nd);
	// printf("\n[[%s]]\n", nd->content);
	return ((*nd)->content);
}

int	start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	t_nd	*coms;
	t_hist	*history;

	status = EXIT_SUCCESS;
	start_write();
	// history = history_init();
	history = 0;
	signal(SIGINT, (void*)signal_ctlc);
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, (void*)signal_ctlslash);

	
	while (status == EXIT_SUCCESS)
	{
		if (exit_code == 0 || exit_code == 1)
			write(1, "minishell test>  ", ft_strlen("minishell test>  "));
		else
			exit_code = 0;
		// line = read_line();
		// history->next = history_init();
		// history->next->prev = history;
		// line = get_ch(history->next);
		history = history_add(history);
		// printf("\n[[%p]]\n", history);
		line = get_ch(&history);
		
		if (*line && line_check(line) && synerror_checker(line, ';') >= 0)
		{
			coms = big_cutter(line);
			status = run_cmd(coms->child, en, av);
		}
		// history = history->next;
	}
	return (0);
}
