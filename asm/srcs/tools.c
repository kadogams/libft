/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:46:24 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/11 15:28:45 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	skip_whitespace(char *str, t_asm *env)
{
	int	i;

	i = 0;
	if (!str)
		quit(env);
	while (str && str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	return (i);
}

int		check_last_line(char *line, int option, t_asm *env)
{
	char	*str;
	int		i;

	str = ft_strchr(line, '"');
	if (option)
		str = ft_strchr(str + 1, '"');
	i = skip_whitespace(str + 1, env) + 1;
	if (str[i] == '\0')
	{
		ft_strdel(&env->line);
		return (OK);
	}
	ft_strdel(&env->line);
	return (KO);
}

void	skip_blank_lines(t_asm *env)
{
	int		ret;
	int		i;

	while ((ret = get_next_line(env->fd_s, &env->line)) > 0)
	{
		i = skip_whitespace(env->line, env);
		if (env->line[i] == '\0')
		{
			ft_strdel(&env->line);
			continue ;
		}
		else
			return ;
	}
	if (ret == -1)
		quit(env);
	return ;
}
