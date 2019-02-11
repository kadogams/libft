/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:50:48 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/11 15:46:17 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fill_prog_name(header_t *header, t_asm *env, char *line)
{
	static int	index = 0;
	int			i;

	i = 0;
	while (line[i] && line[i] != '"' && index < PROG_NAME_LENGTH)
		header->prog_name[index++] = line[i++];
	//ft_printf("index prog name = %d\n", index);
	//ft_printf("prog naaaaaaaaame = |%s|\n", header->prog_name);
	if (index == PROG_NAME_LENGTH && line[i] != '"')
		quit(env);
	else if (line[i] == '"')
	{
		env->read_name = 1;
		return (0);
	}
	else
		header->prog_name[index++] = '\n';
	return (1);
}

int		fill_comment(header_t *header, t_asm *env, char *line)
{
	static int	index = 0;
	int			i;

	i = 0;
	while (line[i] && line[i] != '"' && index < COMMENT_LENGTH)
		header->comment[index++] = line[i++];
	if (index > COMMENT_LENGTH && line[i] != '"')
		quit(env);
	else if (line[i] == '"')
	{
		env->read_comment = 1;
		return (0);
	}
	else
		header->comment[index++] = '\n';
	return (1);
}

void	parse_comment(header_t *header, t_asm *env)
{
	int		ret;
	int		i;

	ft_bzero(header->comment, COMMENT_LENGTH);
	skip_blank_lines(env);
	i = skip_whitespace(env->line, env);
	if (ft_strncmp(env->line + i, ".comment", 8))
		quit(env);
	i = skip_whitespace(env->line + i + 8, env) + i + 8;
	if (env->line[i] != '"')
		quit(env);
	if (!fill_comment(header, env, env->line + i + 1))
	{
		check_last_line(env->line, 1, env);
		return ;
	}
	ft_strdel(&env->line);
	while ((ret = get_next_line(env->fd_s, &env->line)) > 0)
	{
		if (!fill_comment(header, env, env->line))
		{
			check_last_line(env->line, 0, env);
			ft_strdel(&env->line);
			break ;
		}
		ft_strdel(&env->line);
	}
}

void	parse_name(header_t *header, t_asm *env)
{
	int		ret;
	int		i;

	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	skip_blank_lines(env);
	i = skip_whitespace(env->line, env);
	if (ft_strncmp(env->line + i, ".name", 5))
		quit(env);
	i = skip_whitespace(env->line + i + 5, env) + i + 5;
	if (env->line[i] != '"')
		quit(env);
	if (!fill_prog_name(header, env, env->line + i + 1))
	{
		check_last_line(env->line, 1, env);
		return ;
	}
	ft_strdel(&env->line);
	while ((ret = get_next_line(env->fd_s, &env->line)) > 0)
	{
		if (!fill_prog_name(header, env, env->line))
		{
			check_last_line(env->line, 0, env);
			ft_strdel(&env->line);
			break ;
		}
		ft_strdel(&env->line);
	}
}

void	start_parsing(header_t *header, t_asm *env)
{
	parse_name(header, env);
	if (env->read_name == 0)
		quit(NULL);
	ft_printf("Prog name = |%s|", header->prog_name);
	parse_comment(header, env);
	if (env->read_comment == 0)
		quit(NULL);
	ft_printf("comment = |%s|", header->comment);
}
