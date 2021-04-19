/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:40:27 by skim              #+#    #+#             */
/*   Updated: 2021/04/19 19:06:02 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>

# define BLT_NUM 4
# define SEP " \t\n\r\a\""

# define TYPE_NONE	-1
# define TYPE_C_P 	1
# define TYPE_P_C 	2
# define TYPE_RE  	3

# define SIDE_IN	0
# define SIDE_OUT	1

# define STDOUT		1
# define STDIN		0

typedef struct s_red
{
	int		rdrt_yn;
	int		rdrt_fd;
} t_red;

typedef struct 	s_info
{
	struct s_nd		*head;
	struct s_nd		*tail;
}				t_info;

typedef struct 	s_nd
{
	char			**args;
	struct s_nd		*child;
	struct s_nd		*sible;
	struct s_nd		*prev;
	int				type;
	int				pipes[2];

	t_info			pos;
	t_red			re;
}				t_nd;

int		start_shell(char **en, char *av);

t_nd	*big_parse(char *str);
char	**make_tok(char *str, char *charset);

void	ready_run(t_nd *coms);
int		run(t_nd *cmd, char **en, char *av);

int		cmd_exit(t_nd *com, char **en, char *name);
int		cmd_env(t_nd *com, char **en, char *av);
int		cmd_cd(t_nd *com, char **en, char *av);
int		cmd_pwd(t_nd *com, char **en, char *av);
char	*find_env(char *key, char **en);
char	*find_env_val(char *key, char **en);

t_nd	*new_nd(char *name);
void	print_list(t_nd *com);
int		matrix_line_num(char **matrix);

#endif
