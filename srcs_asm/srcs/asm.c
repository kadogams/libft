#include "asm.h"

void	quit()
{
	exit(0);
}

int	check_valid(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len > 2 && !ft_strcmp(".s", file + len - 2))
		return(OK);
	return(KO);
}

char	*parse_name(char *file)
{
	int	len;
	char	*name;
	char	*tmp;

	tmp = ft_strrchr(file, '/');
	len = (tmp == NULL) ? ft_strlen(file) + 3 : ft_strlen(tmp) + 2;
	if (!(name = (char*)malloc(sizeof(char) * len)))
		quit();
	name[len - 1] = '\0';
	if (tmp == NULL)
		name = ft_strcpy(name, file);
	else
		name = ft_strcpy(name, tmp + 1);
	name[len - 2] = 'r';
	name[len - 3] = 'o';
	name[len - 4] = 'c';
	return (name);
}

int	open_core_file(char *file)
{
	char	*name;
	int		fd;

	name = parse_name(file);
	fd = open("players/stp.cor", O_CREAT | O_APPEND | O_DIRECTORY | O_WRONLY);
	return (fd);
}

header_t	open_file(char *file, header_t *header)
{
	int fd_s;
	int fd_cor;

	fd_s = open(file, O_RDONLY);
	fd_cor = open_core_file(file);
	ft_printf("fd = %d\n", fd_cor);
}

int	main(int ac, char **av)
{
	header_t header;

	if (ac == 2 && check_valid(av[1]))
	{
		open_file(av[1], &header);
	}

}
