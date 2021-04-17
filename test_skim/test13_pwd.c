/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:48:34 by skim              #+#    #+#             */
/*   Updated: 2021/04/17 16:07:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		cmd_pwd(t_nd run_cum, char **en, char *av)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	write(1, pwd, strlen(pwd));
	return (1);
}

// int		main()
// {
// 	char	buf[PATH_MAX];

// 	 getcwd(buf, PATH_MAX);
// 	printf("%s\n", buf);
// }
