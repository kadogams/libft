/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:35:47 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/25 10:16:22 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to check the command line arguments.
*/

void	quit(t_data **data)
{
	delete_data(data);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int		check_flags(char **av, t_data **data)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (av && av[i] && av[i][0] == '-' && !ft_isdigit(av[i][1]))
	{
		if (!((*data)->options & 1) && !ft_strcmp(av[i], "-v"))
		{
			(*data)->options |= 1;
			check++;
		}
		else if (!((*data)->options & (1 << 1)) && !ft_strcmp(av[i], "-n"))
		{
			(*data)->options |= (1 << 1);
			check++;
		}
		i++;
	}
	return (check);
}

int		check_arg(char *s, t_data **data)
{
	int			i;
	intmax_t	j;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]) || i > 10)
			quit(data);
	}
	j = ft_atoimax_base(s, 10);
	if (j < (intmax_t)INT_MIN || j > (intmax_t)INT_MAX)
		quit(data);
	stacknew(&(*data)->a, (int)j);
	return (1);
}
