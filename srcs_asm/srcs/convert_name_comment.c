#include "asm.h"
static int	fill_prog_name(char *line, header_t *header, int i)
{
	char	*str;
	int		j;

	j = 0;
	while (line[j] && i < PROG_NAME_LENGTH)
	{
		if (line[j] == '"')
			return (0);
		//str = ft_itoa_base(line[j], 16, 0);
		header->prog_name[i] = line[j];
	//	header->prog_name[i] = str[1];
	//	free(str);
		j++;
		i++;
	}
	//header->prog_name = ft_strcpy(header->prog_name + i, "0a");
	return (i);
}

static void	parse_name(header_t *header, t_asm *env)
{
	int		ret;
	char	*line;
	int		i;
	char	*str;

	i = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	if ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		if (!ft_strncmp(line, ".name", 5) && (str = ft_strchr(line, '"')))
		{
			i = fill_prog_name(str + 1, header, 0);
			while (i > 0 && (ret = get_next_line(env->fd_s, &line)) > 0)
				i = fill_prog_name(line, header, i);
			ft_printf("heaxa name : %s -- i = %d\n", header->prog_name, i);
		}
	}

}
int					is_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
			i++;
		else
			return (0);
	}
	return (1);
}

static void parse_comment(header_t *header, t_asm *env)
{
	int		ret;
	char	*line;
	int		i;
	chqr *str;

	i = 0;
	ft_bzero(header->comment, COMMENT_LENGTH);
	if ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		ft_printf("line comment = %s\n", line);
		if (is_whitespaces(line))
		{
			ft_printf("ici");
			parse_comment(header, env);
		}
		if (!ft_strncmp(line, ".comment", 5) && (str = ft_strchr(line, '"')))
		{
			i = fille_comment_name()
			while (i > 0 && (ret = get_next_line(env->fd_s, &line)) > 0)
				i = fille_comment_name()
		}
	}
}

void	convert_to_hex(header_t *header, t_asm *env)
{
	parse_name(header, env);
	parse_comment(header, env);
}
