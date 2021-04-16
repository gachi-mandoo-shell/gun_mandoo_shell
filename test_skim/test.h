/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:40:27 by skim              #+#    #+#             */
/*   Updated: 2021/04/16 21:56:53 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

parpar9parparpar6parparpar51parparpar9parparpar5parparpar4parparpar1:2parparpar9parparpar8parparpar8parparpar6parparpar5parparpar2parparpar5parparpar3parparpar2parparpar31parparpar9parparpar8parparpar6parparpar20parparpar1parparpar9parparpar8parparpar5parparpar4parparpar2parparpar3000parparpar9parparpar8parparpar5parparpar4parparpar2parparpar51parparpar9parparpar7parparpar6parparpar4parparpar1parparpar40parparpar8parparpar6parparpar4parparpar1parparpar30parparpar8parparpar7parparpar6parparpar5parparpar3parparpar20parparpar9:1parparpar2parparpar11parparpar9parparpar8parparpar7parparpar6parparpar3parparpar2parparpar500parparpar8parparpar6parparpar5parparpar4parparpar3parparpar2parparpar31parparpar9parparpar8parparpar7parparpar6parparpar5parparpar4parparpar2parparpar2parparpar3parparpar2parparpar401parparpar9parparpar8parparpar7parparpar6parparpar5parparpar4parparpar3parparpar2parparpar50parparpar9parparpar8parparpar7parparpar6parparpar5parparpar4parparpar2parparpar1parparpar40parparpar9parparpar8parparpar7parparpar6parparpar5parparpar3parparpar2parparpar1parparpar30parparpar5parparpar4parparpar3parparpar2parparpar2parparpar9parparpar8parparpar6parparpar7parparpar6parparpar5parparpar4parparpar3:0parparpar2parparpar50parparpar9parparpar8parparpar40parparpar8parparpar7parparpar5parparpar4parparpar3parparpar31parparpar8parparpar5parparpar20parparpar8parparpar7parparpar6parparpar4parparpar12parparpar9parparpar7parparpar5par4parpar50parparpar9parparpar7parparpar6parparpar4parparpar2parparpar41parparpar9parparpar8parparpar7par#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <string.h>
# include <unistd.h>

# define BLT_NUM 2

TYPE_NONE	-1
TYPE_NONE	-1
TYPE_C_P 	1
TYPE_P_C 	2
TYPE_RE  	3

typedef struct s_red
{
	int		rdrt_yn;
	int		rdrt_fd;
} t_red

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
char	**make_tok(char *str, char *charset);
int		run(char **run_com, char **en, char *av);

int		cmd_exit(char **run_com, char **en, char *name);
int		cmd_env(char **run_com, char **en, char *av);
char	*find_env(char *key, char **en);

#endif
