#include "asm.h"
static int	fill_prog_name(char *line, header_t *header, int i)
{
	char	*str;
	int		j;

	j = 0;
	while (line[j] && i < PROG_NAME_LENGTH)
	{
		if (line[j] == '"')
			return (check_)
		str = ft_itoa_base(line[j], 16);
		header->prog_name[i] = ft_strcpy(prog_name[i], str);
		free(str);
		j++;
		i++;
	}
	header->prog_name[i] = ft_strcpy(prog_name[i], "0a");
	return (++i);
}

static void	parse_name(header_t *header, t_asm *env)
{
	int		ret;
	char	*line;
	int		i;
	char	*str;

	i = 0;
	if ((ret = get_next_line(env->fd_s, &line)) > 0)
	{
		ft_printf("test\n");
		if (!ft_strncmp(line, ".name", 5) && str = ft_strchr(line, '"'))
		{
			i = fill_prog_name(str + 1, header, 0);
			while ((ret = get_next_line(env->fd_s, &line)) > 0)
				i = fill_prog_name(line, header, i);
		}
	}

}

void	convert_to_hex(header_t *header, t_asm *env)
{
	parse_name(header, env);
}
