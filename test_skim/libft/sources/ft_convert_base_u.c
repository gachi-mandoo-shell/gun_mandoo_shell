/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 06:08:16 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 21:17:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ui	nbr_divide(unsigned long long nbr, int base_len)
{
	int	cnt;

	if (!nbr)
		return (1);
	cnt = 0;
	if (nbr < 0)
		++cnt;
	while (nbr)
	{
		nbr = nbr / base_len;
		++cnt;
	}
	return (cnt);
}

static int	str_check(char *str, int *len)
{
	int		idx;
	int		checker[256];
	char	c;

	if (!*str)
		return (0);
	idx = 0;
	while (idx < 256)
		checker[idx++] = 0;
	*len = 0;
	while (str[*len])
	{
		c = str[*len];
		if (checker[(int)c] || c == '+' || c == '-' || is_space(c))
			return (0);
		checker[(int)c] = 1;
		++*len;
	}
	if (*len <= 1)
		return (0);
	return (1);
}

static t_ull	atoi_base_from(char *str, char *base, int base_len)
{
	unsigned long long	ret;
	int					indic;
	int					idx;

	ret = 0;
	indic = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			indic = indic * -1;
	while (*str)
	{
		idx = -1;
		while (++idx < base_len)
		{
			if (*str == base[idx])
				break ;
		}
		if (idx == base_len)
			break ;
		ret = ret * base_len + (idx * indic);
		++str;
	}
	return (ret);
}

static char	*convert_to(t_ull nbr, char *base, int base_len)
{
	unsigned long long	tmp;
	char				*ret;
	int					size;

	if (nbr == 0)
	{
		ret = (char *)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_divide(tmp, base_len);
	ret = (char *)malloc(size + 2);
	if (!ret)
		return (0);
	ret[size] = 0;
	ret[size + 1] = 0;
	if (tmp < 0)
		tmp = tmp * -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp = tmp / base_len;
	}
	if = nbr < 0 ? '-' : ret[0];
	return (ret);
}

char			*ft_convert_base_u(char *nbr, char *base_from, char *base_to)
{
	unsigned long long	tmp;
	int					from_len;
	int					to_len;
	char				*ret;

	if (!(str_check(base_from, &from_len)) || !(str_check(base_to, &to_len)))
		return (0);
	tmp = atoi_base_from(nbr, base_from, from_len);
	ret = convert_to(tmp, base_to, to_len);
	return (ret);
}
