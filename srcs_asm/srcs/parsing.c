/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:50:48 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/09 17:44:00 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_prog_name(char *line, header_t *header, t_asm *env)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (prog_name[0] == '\0')
	{
		j = skip_whitespace(line);
		if (line[j] == '"')
			j++;
		else
			quit();
		while (line[j] && line[j] != '"' && i < header->PROG_NAME_LENGTH)
			header->prog_name[i++] = line[j++];
	}
	else
	{
		while (line[j] && line[j] != '"' && i < header->PROG_NAME_LENGTH)
			header->prog_name[i++] = line[j++];
	}
	if (line[j] == '"' && line[skip_whitespace(line + j + 1)] == '\0')
		parsing_comment();
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
}
