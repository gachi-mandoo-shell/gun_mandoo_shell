#include "minishell.h"


int	redirect_count(char *arg)
{
	int	qq_f;
	int	q_f;
	int	i;
	int	count;
	int	red_pos;

	i = -1;
	qq_f = 1;
	q_f = 1;
	count = 1;
	red_pos = -1;
	if (is_redirect(arg))
		return (1);
	while (arg[++i])
	{
		if (arg[i] == '\'')
			q_f *= -1;
		else if (arg[i] == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			if (arg[i + 1] == '>')
				i++;
			red_pos = i;
			// if (arg[i + 1])
			count++;
			// count++;
		}
	}
	if ((red_pos >= 0) && (red_pos != i - 1) &&  (arg[0] != '>' && arg[0] != '<'))
		count++;
	return (count);
}

void	sep_redirect(char ***rt, int *size, char *arg)
{
	char	temp[1024];
	int		qq_f;
	int		q_f;
	int		j;

	j = 0;
	qq_f = 1;
	q_f = 1;
	ft_memset(temp, 0, 1024);
	while (*arg)
	{
		if (*arg == '\'')
			q_f *= -1;
		else if (*arg == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (*arg == '>' || *arg == '<'))
		{
			if (ft_strlen(temp) > 0)
			{
				(*rt)[*size] = ft_strdup(temp);
				ft_memset(temp, 0, 1024);
				j = 0;
				(*size)++;
			}
			temp[j++] = *arg;
			if (*(arg + 1) == '>')
				temp[j++] = *(arg++);
			(*rt)[*size] = ft_strdup(temp);
			ft_memset(temp, 0, 1024);
			j = 0;
			(*size)++;
		}
		else
			temp[j++] = *arg;
		arg++;
	}
	if (ft_strlen(temp) > 0)
	{
		(*rt)[*size] = ft_strdup(temp);
		(*size)++;
	}
}

char	**split_redirect(char **b_arg)
{
	char	**rt;
	int		size;
	int		i;

	size = 0;
	i = -1;
	while (b_arg[++i])
		size += redirect_count(b_arg[i]);
	rt = (char **)malloc(sizeof(char *) * (size + 1));
	rt[size] = 0;
	i = -1;
	size = 0;
	while (b_arg[++i])
	{
		if (redirect_count(b_arg[i]) == 1)
			rt[size++] = ft_strdup(b_arg[i]);
		else
			sep_redirect(&rt, &size, b_arg[i]);
	}
	return (rt);
}
