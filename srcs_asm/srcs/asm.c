#include "asm.h"

void	quit()
{
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
		quit();
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

 static int	open_core_file(char *file)
{
	char	*name;
	int		fd;

	name = parse_name(file);
	fd = open(name, O_CREAT | O_APPEND | O_WRONLY | O_TRUNC);
	return (fd);
}

static void	open_file(char *file, header_t *header, t_asm *env)
{

	env->fd_s = open(file, O_RDONLY);
	env->fd_cor = open_core_file(file);
	ft_printf("fd = %d\n", env->fd_cor);
}

int	main(int ac, char **av)
{
	header_t	header;
	t_asm 		env;
	int			fd;

	if (ac == 2 && check_valid(av[1]))
	{
		open_file(av[1], &header, &env);
		if (env.fd_cor)
			convert_to_hex(&header, &env);
	}
	return (0);
}
