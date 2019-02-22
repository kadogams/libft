/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:21:39 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/22 17:42:19 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO registre > 16
//TODO write return error?

static int	check_valid(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len > 2 && !ft_strcmp(".s", file + len - 2))
		return (OK);
	return (KO);
}

//TODO FREE STRJOIN

static char	*parse_file_name(char *file)
{
	char	*name;
	char	*tmp;
	int		len;

	len = ft_strlen(file);
	name = ft_strsub(file, 0, len - 2);
	name = ft_strjoin(name, ".cor");
	return (name);
}

static int	open_cor_file(char *file, t_asm *env)
{
	env->output = parse_file_name(file);
	env->fd_cor = open(env->output, O_CREAT | O_RDWR, 0644);
	return (1);
}

int			main(int ac, char **av)
{
	t_header	header;
	t_asm		env;

	if (ac == 2 && check_valid(av[1]))
	{
		init_env(&env);
		if ((env.fd_s = open(av[1], O_RDONLY)) == -1)
			return (ft_error(READ, &env));
		if (!start_parsing(&header, &env))
			return (KO);
		else
		{
			open_cor_file(av[1], &env);
			write_cor_file(&env, &header);
			ft_printf("Writing output program to %s\n", env.output);
		}
	}
	else
		return (ft_error(USAGE, &env));
	return (0);
}
