#include "minishell.h"

int	is_redirect(char *str)
{
	if (!strcmp(str, ">") || !strcmp(str, ">>") || !strcmp(str, "<"))
		return (1);
	else
		return (0);
}

void	get_redirect_type(t_nd *nd, int arg_count)
{
	if (nd->args[arg_count][1] == '>')
		nd->re.rdrt_type = RE_TYPE_OOUT;
	else if (nd->args[arg_count][0] == '>')
		nd->re.rdrt_type = RE_TYPE_OUT;
	else if (nd->args[arg_count][0] == '<')
		nd->re.rdrt_type = RE_TYPE_IN;
}

int	get_redirect_fd(t_nd *nd, char **en)
{
	if (nd->re.rdrt_type == RE_TYPE_OUT)
		nd->re.rdrt_fd = open(nd->re.rdrt_name, O_RDWR | O_CREAT | O_TRUNC);
	else if (nd->re.rdrt_type == RE_TYPE_OOUT)
		nd->re.rdrt_fd = open(nd->re.rdrt_name, O_RDWR | O_CREAT | O_APPEND);
	else if (nd->re.rdrt_type == RE_TYPE_IN)
		nd->re.rdrt_fd = open(nd->re.rdrt_name, O_RDONLY);
	if (nd->re.rdrt_fd < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_redirect_info(t_nd *nd, int arg_count, char **en)
{
	if (nd->re.rdrt_type > 0)
	{
		close(nd->re.rdrt_fd);
		free(nd->re.rdrt_name);
	}
	get_redirect_type(nd, arg_count);
	free(nd->args[arg_count]);
	nd->args[arg_count] = 0;
	nd->re.rdrt_name = env_controller(nd->args[arg_count + 1], en);
	free(nd->args[arg_count + 1]);
	nd->args[arg_count + 1] = 0;
	if (get_redirect_fd(nd, en) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int change_arg(t_nd *nd, int arg_count)
{
	char	**c_arg;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < arg_count)
	{
		if (nd->args[i])
			count++;
	}
	c_arg = malloc(sizeof(char *) * (count + 1));
	if (!c_arg)
		return (EXIT_FAILURE);
	c_arg[count] = 0;
	i = -1;
	count = 0;
	while (++i < arg_count)
	{
		if (nd->args[i])
		{
			c_arg[count++] = ft_strdup(nd->args[i]);
			free(nd->args[i]);
		}
	}
	free(nd->args);
	nd->args = c_arg;
	return (EXIT_SUCCESS);
}

int	get_redirect(t_nd *nd, char **en)
{
	t_nd	*anc;
	int		arg_count;
	int		red_pos;
	int		rt;

	anc = nd;
	while (anc)
	{
		arg_count = -1;
		while (anc->args[++arg_count])
		{
			if (is_redirect(anc->args[arg_count]))
				get_redirect_info(anc, arg_count++, en);
		}
		if (change_arg(anc, arg_count) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (anc->sible)
			anc = anc->sible;
		else
			break ;
	}
	return (EXIT_SUCCESS);
}
