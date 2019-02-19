/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:21:39 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/19 13:24:01 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO COMMENTAIRE + GESTION ERREUR + CREATION FICHIER

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

static char	*parse_name(char *file)
{
	int	len;
	char	*name;
	char	*tmp;

	tmp = ft_strrchr(file, '/');
	len = (tmp == NULL) ? ft_strlen(file) + 3 : ft_strlen(tmp) + 10;
	if (!(name = (char*)malloc(sizeof(char) * len)))
		quit(NULL);
	name[len - 1] = '\0';
	if (tmp == NULL)
	{
		name = ft_strcpy(name, "players/");
		name = ft_strcat(name, file);
	}
	else
	{
		name = ft_strcpy(name, "players/");
		name = ft_strcat(name, tmp + 1);
	}
	name[len - 2] = 'r';
	name[len - 3] = 'o';
	name[len - 4] = 'c';
	return (name);
}

static int	open_core_file(char *file, t_asm *env)
{
	char	*name;
	int		fd;

	env->output = parse_name(file);
	fd = open(env->output, O_CREAT | O_RDWR, 0644);
	return (fd);
}

static void	open_file(char *file, header_t *header, t_asm *env)
{

	env->fd_s = open(file, O_RDONLY);
	env->fd_cor = open_core_file(file, env);
	ft_printf("fd = %d\n", env->fd_cor);
}

int	main(int ac, char **av)
{
	header_t	header;
	t_asm 		env;
	int			fd;


	if (ac == 2 && check_valid(av[1]))
	{
		init_env(&env);
		open_file(av[1], &header, &env);

//		if (env.fd_cor)
			if (!start_parsing(&header, &env))
				ft_printf("cur_x = %d\n cur_y = %d\n", env.cur_x, env.cur_y);
			else
			{
				write(env.fd_cor, header.prog_name, PROG_NAME_LENGTH);
				write(env.fd_cor, header.comment, COMMENT_LENGTH);
				write(env.fd_cor, env.code, env.index);
				ft_printf("ASM OK\n");
			}
	}
	return (0);
}
