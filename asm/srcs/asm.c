/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:21:39 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/20 11:59:05 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO COMMENTAIRE + GESTION ERREUR

void	quit(t_asm *env)
{
	ft_strdel(&env->line);
	ft_printf("QUIT\n");
	exit(0);
}

static int	check_valid(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len > 2 && !ft_strcmp(".s", file + len - 2))
		return(OK);
	return(KO);
}

//TODO FREE STRJOIN

char	*parse_file_name(char *file)
{
	char	*name;
	char	*tmp;
	int		len;

	len = ft_strlen(file);
	name = ft_strsub(file, 0, len - 2);
	name = ft_strjoin(name, ".cor");
	ft_printf("name = %s\n", name);
	return (name);
}

int		open_cor_file(char *file, t_asm *env)
{
	env->output = parse_file_name(file);
	env->fd_cor = open(env->output, O_CREAT | O_RDWR, 0644);
	return (1);
}

int	main(int ac, char **av)
{
	header_t	header;
	t_asm 		env;

	if (ac == 2 && check_valid(av[1]))
	{
		init_env(&env);
		if ((env.fd_s = open(av[1], O_RDONLY)) == -1)
			return (KO);
			if (!start_parsing(&header, &env))
				ft_printf("cur_x = %d\n cur_y = %d\n", env.cur_x, env.cur_y);
			else
			{
				open_cor_file(av[1], &env);
				write_cor_file(&env, &header);
				ft_printf("ASM OK\n");
			}
	}
	return (0);
}
