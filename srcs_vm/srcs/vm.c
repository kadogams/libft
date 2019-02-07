/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:09:56 by skadogam          #+#    #+#             */
/*   Updated: 2019/02/07 17:54:01 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	put_usage(void)
{
	write(1, "Usage: ./corewar [-d N -s N -v N | -b --stealth "
	"| -n --stealth] [-a] <champion1.cor> <...>\n"
	"\t-a\t  : Prints output from \"aff\" (Default is to hide it)\n"
	"#### TEXT OUTPUT MODE "
	"##########################################################\n"
	"\t-d N\t  : Dumps memory after N cycles then exits\n"
	"\t-s N\t  : Runs N cycles, dumps memory, pauses, then repeats\n"
	"\t-v N\t  : Verbosity levels, can be added together to enable several\n"
	"\t\t    - 0 : Show only essentials\n"
	"\t\t    - 1 : Show lives\n"
	"\t\t    - 2 : Show cycles\n"
	"\t\t    - 4 : Show operations (Params are NOT litteral ...)\n"
	"\t\t    - 8 : Show deaths\n"
	"\t\t    - 16 : Show PC movements (Except for jumps)\n"
	"#### BINARY OUTPUT MODE "
	"########################################################\n"
	"\t-b\t  : Binary output mode for corewar.42.fr\n"
	"\t--stealth : Hides the real contents of the memory\n"
	"#### NCURSES OUTPUT MODE "
	"#######################################################\n"
	"\t-n\t  : Ncurses output mode\n"
	"\t--stealth : Hides the real contents of the memory\n"
	"######################################################################"
	"##########\n", 1037);
}
# define BUFF_SIZE2 8196
void	get_champions(int ac, char **av)
{
	int		i;
	int		j;
	int		fd;
	int		ret;
	char	*line;
	char	buff[BUFF_SIZE2 + 1];

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		printf("fd: %d\n", fd);
		while ((ret = read(fd, buff, BUFF_SIZE2)) > 0)
		{
			buff[ret] = 0;
//			printf("\nret: %d\n", ret);
			j = 0;
			while (j < ret)
			{
				printf("%x ", (unsigned char)buff[j++]);
				if (j && !(j % 16))
					printf("\n");
			}
			printf("\n");
		}
		printf("ret2: %d\n", ret);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 1)
		put_usage();
	else if (ac < 6)
		{
			get_champions(ac, av);
		}
	else
		write(1, "Too many champions\n", 19);
	return (0);
}
