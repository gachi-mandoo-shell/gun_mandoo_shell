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
# include <signal.h>
# include <termios.h>

# define BLT_NUM 4
# define SEP " \t\n\r\a\""

# define TYPE_NONE	-1
# define TYPE_C_P 	1

# define RE_TYPE_OUT  	1
# define RE_TYPE_OOUT	2
# define RE_TYPE_IN  	3

#define SIDE_OUT	0
#define SIDE_IN		1

# define STDOUT		1
# define STDIN		0

int 			exit_code;

typedef struct 	s_hist
{
	char			*content;
	struct s_hist	*next;
	struct s_hist	*prev;
	int				count;
} t_hist;

typedef struct s_red
{
	int		rdrt_type;
	int		rdrt_in_type;
	char	*rdrt_name;
	char	*rdrt_in_name;
	int		rdrt_fd;
	int		rdrt_in_fd;
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
int		synerror_checker(char *args, char a);
int		synerror_redirect(char *arg);
char	**split_quote(char *str, char *set);
char	**split_redirect(char **b_arg);

t_nd	*big_cutter(char *str);

int		lexer(t_nd *new, char *args);
int		tokenizer(t_nd *nd);

int		token_changer(t_nd *nd, char **en);
int		get_redirect(t_nd *nd, char **en);


int		run(t_nd *cmd, char **en, char *av);
int		pipe_dup(t_nd *cmd);
void	pipe_close(t_nd *cmd);

int		builtin_run(t_nd *cmd, char **en, char *av, int i);
int		(*blt_func(int i))(t_nd *cmd, char **en, char *av);
char	*blt_str(int i);

void	find_cmd(t_nd *com, char **en, char *av);
int		execute_ps(char *run_com, t_nd *com, char **en, char *name);

// built_in
int		cmd_exit(t_nd *com, char **en, char *name);
int		cmd_env(t_nd *com, char **en, char *av);
int		cmd_cd(t_nd *com, char **en, char *av);
int		cmd_pwd(t_nd *com, char **en, char *av);
char	*find_env(char *key, char **en);
char	*find_env_val(char *key, char **en);

// util
t_nd	*new_nd(char *name);
t_nd	*child_rewind(t_nd *coms);
void	print_list(t_nd *com);
int		matrix_line_num(char **matrix);

// signal
void	*signal_ctlc(int	signo);
void	*signal_ctld(int	signo);
void	*signal_ctlslash(int	signo);
void	*signal_child_ctld(int	signo);
void	*signal_child_ctlslash(int	signo);
void	*signal_child_ctlc(int signo);
t_hist	*history_add(t_hist *nd);
t_hist	*history_init();

void	print_list_2(t_hist *com);

char	*get_ch(t_hist	*nd);
int		is_redirect(char *str);

#endif
