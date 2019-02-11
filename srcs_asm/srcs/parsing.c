/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:50:48 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/11 13:36:37 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*void	parsing_comment(header_t *header, t_asm *env)
{
	ft_printf("%s\n", header->prog_name);
}

void	fill_prog_name(char *line, header_t *header, t_asm *env)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (header->prog_name[0] == '\0')
	{
		j = skip_whitespace(line);
		if (line[j] == '"')
			j++;
		else
			quit();
		while (line[j] && line[j] != '"' && i < PROG_NAME_LENGTH)
			header->prog_name[i++] = line[j++];
	}
	else
	{
		while (line[j] && line[j] != '"' && i < PROG_NAME_LENGTH)
			header->prog_name[i++] = line[j++];
	}
	if (line[j] == '"' && line[skip_whitespace(line + j + 1)] == '\0')
		parsing_comment(header, env);
}

void	start_parsing(header_t *header, t_asm *env)
{
	char	*line;
	int		ret;
	int		i;

	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	while ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		i = skip_whitespace(line);
		if (line[i] == '\0')
		{
			free(line);
			continue ;
		}
		else if (!ft_strncmp(line + i, ".name", 5))
		{
			fill_prog_name(line + i + 5, header, env);
			free(line);
			parse_name();
		}
		else
			quit();
	}
}*/

char	*skip_blank_lines(t_asm *env)
{
	char	*line;
	int		ret;
	int		i;

	while ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		i = skip_whitespace(line);
		if (line[i] == '\0')
		{
			ft_strdel(&line);
			continue ;
		}
		else
			return (line);
	}
	if (ret == -1)
		quit(NULL);
	return (NULL);
}

int		fill_prog_name(header_t *header, t_asm *env, char *line)
{
	static int	index = 0;
	int			i;

	i = 0;
	while (line[i] && line[i] != '"' && i < PROG_NAME_LENGTH)
		header->prog_name[index++] = line[i++];
	if (index >= PROG_NAME_LENGTH)
		quit(&line);
	else if (line[i] == '"')
	{
		env->read_name = 1;
		return (0);
	}
	else
		header->prog_name[index++] = '\n';
	return (1);
}

int		check_last_line(char *line)
{
	char	*str;
	int		i;

	str = ft_strchr(line, '"');
	i = skip_whitespace(line + i + 1);
	if (line[i] == '\0')
		return (1);
	return (0);
}

void	parse_name(header_t *header, t_asm *env)
{
	char	*line;
	int		ret;
	int		i;

	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_printf("test5\n");
	line = skip_blank_lines(env);
	ft_printf("test6\n");
	ft_printf("line = %s\n", line);
	i = skip_whitespace(line);
	ft_printf("test1\n");
	if (ft_strncmp(line + i, ".name", 5))
		quit(&line);
	ft_printf("test2\n");
	i = skip_whitespace(line + i + 5) + i + 5;
	ft_printf("i = %d et line[i] = %c\n", i, line[i]);
	if (line[i] != '"')
	{
		ft_printf("jquit\n");
		quit(&line);
	}
	ft_printf("test3\n");
	fill_prog_name(header, env, line + i + 6);
	ft_strdel(&line);
	while ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		if (!fill_prog_name(header, env, line))
			break ;
		ft_strdel(&line);
	}
	if (!check_last_line(line))
		quit(&line);
	ft_printf("test4\n");
	ft_strdel(&line);
}

void	start_parsing(header_t *header, t_asm *env)
{
	parse_name(header, env);
	if (env->read_name == 0)
		quit(NULL);
	ft_printf("Prog name = |%s|", header->prog_name);
}
