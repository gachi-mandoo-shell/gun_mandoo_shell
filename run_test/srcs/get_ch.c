#include "minishell.h"

void	delete_char(int size)
{
	char	alt[size * 2];
	int 	i;

	i = -1;
	while (++i < size)
		alt[i] = '\b';
	while (i < size * 2)
		alt[i++] = ' ';
	write(1, alt, size * 2);
	write(1, alt, size);
}

void	get_ch_3(t_hist **nd, char *c, t_hist **anc, char (*fake_db)[(*nd)->count + 1][PATH_MAX])
{
	char			*tmp_back;
	char			*tmp;

	if ((int)c[0] == 127)
	{
		if (*(*nd)->content && *((*nd)->content))
		{
			delete_char(ft_strlen((*nd)->content));
			tmp_back = ft_strndup((*nd)->content, ft_strlen((*nd)->content) - 1);
			free((*nd)->content);
			(*nd)->content = tmp_back;
			write(1, (*nd)->content, ft_strlen((*nd)->content));
		}
	}
	else
	{
		write(1, c, 1);
		if ((*anc) != (*nd))
		{
			if (c[0] == '\n')
			{
				free((*anc)->content);
				(*anc)->content = ft_strdup((*nd)->content);
				if (fake_db[(*nd)->count][0])
				{
					free((*nd)->content);
					(*nd)->content = ft_strdup(fake_db[(*nd)->count]);
				}
				(*nd) = (*anc);
			}
			else
			{
				if ((*fake_db)[(*nd)->count][0] == 0)
					ft_strlcpy((*fake_db)[(*nd)->count], (*nd)->content, ft_strlen((*nd)->content) + 1);
			}
		}
		if (c[0] == '\n')
			;
		if (!(*nd)->content)
			(*nd)->content = ft_strdup(c);
		else
		{
			c[1] = 0;
			tmp = (*nd)->content;
			(*nd)->content = ft_strjoin(tmp, c);
			free(tmp);
		}
	}
}

void	terminal_set(struct termios	*term, struct termios *back)
{
	tcgetattr(STDIN_FILENO, term);
	tcgetattr(STDIN_FILENO, back);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, term);
}

void	get_ch_2(t_hist **nd, char *c, t_hist **anc)
{
	if ((int)c[0] == 65)
	{
		if ((*nd)->prev && (*nd)->content)
			delete_char(ft_strlen((*nd)->content));
		if ((*nd)->prev)
		{
			write(1, (*nd)->prev->content, ft_strlen((*nd)->prev->content));
			(*nd) = (*nd)->prev;
		}
	}
	else if ((int)c[0] == 66)
	{
		if ((*nd) != (*anc) && (*nd)->content)
			delete_char(ft_strlen((*nd)->content));
		if ((*nd) != (*anc))
		{
			if ((*nd)->next->content)
				write(1, (*nd)->next->content, ft_strlen((*nd)->next->content));
			(*nd) = (*nd)->next;
		}
	}
}

char	*get_ch(t_hist	*nd)
{
	char			c[2];
	char			*tmp;
	// char			*tmp_back;
	struct termios	term;
	struct termios	back;
	char			fake_db[nd->count + 1][PATH_MAX];
	t_hist			*anc;

	c[1] = 0;
	terminal_set(&term, &back);
	anc = nd;
	ft_memset(fake_db, 0, sizeof(fake_db));
	while (read(0, c, 1) > 0)
	{
		if ((int)c[0] == 4 && !nd->content)
		{
			free_hist(nd);
			printf("exit\n");
			exit(0);
		}
		else if ((int)c[0] == 4 && nd->content)
			;
		else if ((int)c[0] == 27)
		{
			read(0, c, 1);
			if ((int)c[0] == 91)
			{
				read(0, c, 1);
				get_ch_2(&nd, c, &anc);
			}
		}
		else if ((int)c[0] == 127)

		get_ch_3(&nd, c, &anc, &fake_db);
		// {
		// 	if (nd->content && *(nd->content))
		// 	{
		// 		delete_char(ft_strlen(nd->content));
		// 		tmp_back = ft_strndup(nd->content, ft_strlen(nd->content) - 1);
		// 		free(nd->content);
		// 		nd->content = tmp_back;
		// 		write(1, nd->content, ft_strlen(nd->content));
		// 	}
		// }
		// else
		// {
		// 	write(1, c, 1);
		// 	if (anc != nd)
		// 	{
		// 		if (c[0] == '\n')
		// 		{
		// 			free(anc->content);
		// 			anc->content = ft_strdup(nd->content);
		// 			if (fake_db[nd->count][0])
		// 			{
		// 				free(nd->content);
		// 				nd->content = ft_strdup(fake_db[nd->count]);
		// 			}
		// 			nd = anc;
		// 		}
		// 		else
		// 		{
		// 			if (fake_db[nd->count][0] == 0)
		// 				ft_strlcpy(fake_db[nd->count], nd->content, ft_strlen(nd->content) + 1);
		// 		}
		// 	}
		// 	if (c[0] == '\n')
		// 		break ;
		// 	if (!nd->content)
		// 		nd->content = ft_strdup(c);
		// 	else
		// 	{
		// 		c[1] = 0;
		// 		tmp = nd->content;
		// 		nd->content = ft_strjoin(tmp, c);
		// 		free(tmp);
		// 	}
		// }
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &back);
	return (nd->content);
}
