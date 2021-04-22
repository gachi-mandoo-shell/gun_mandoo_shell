#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>

# define BLT_NUM 4
# define SEP " \t\n\r\a\""

# define TYPE_NONE	-1
# define TYPE_C_P 	1

# define RE_TYPE_OUT  	1
# define RE_TYPE_IN  	2

#define SIDE_OUT	0
#define SIDE_IN		1

# define STDOUT		1
# define STDIN		0

typedef struct s_red
{
	int		rdrt_type;
	int		rdrt_fd;
} t_red;

typedef struct 	s_info
{
	struct s_nd		*head;
	struct s_nd		*tail;
} t_info;

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

char	**make_tok(char *str, char *charset);
char	**split_qoute(char *str, char *set);
int		lexer(t_nd *new, char *args);

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

int		make_mini_tok(t_nd *nd, char **en);
t_nd	*make_big_tok(char *str);

char	*env_controller(char *args, char **en);
int		env_changer(char *args, int *arg_i, char *cpy_arg, char **en);
t_nd	*child_rewind(t_nd *coms);
int		call_env(t_nd *nd, char **en);
int		synerror_checker(char *args, char a);
int		syntax_check(t_nd *nd);

#endif
