/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:35:53 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:42:40 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main of the checker program.
*/

static int	check_op(char *line, t_stack **commands)
{
	if (!ft_strcmp(line, "sa"))
		stacknew(commands, 0);
	else if (!ft_strcmp(line, "sb"))
		stacknew(commands, 1);
	else if (!ft_strcmp(line, "ss"))
		stacknew(commands, 2);
	else if (!ft_strcmp(line, "pa"))
		stacknew(commands, 3);
	else if (!ft_strcmp(line, "pb"))
		stacknew(commands, 4);
	else if (!ft_strcmp(line, "ra"))
		stacknew(commands, 5);
	else if (!ft_strcmp(line, "rb"))
		stacknew(commands, 6);
	else if (!ft_strcmp(line, "rr"))
		stacknew(commands, 7);
	else if (!ft_strcmp(line, "rra"))
		stacknew(commands, 8);
	else if (!ft_strcmp(line, "rrb"))
		stacknew(commands, 9);
	else if (!ft_strcmp(line, "rrr"))
		stacknew(commands, 10);
	else
		return (0);
	return (1);
}

static int	check_res(t_data **data)
{
	t_stack	*tmp;

	tmp = (*data)->a;
	while (--(*data)->size)
	{
		if (tmp->content >= tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (tmp->next == (*data)->a);
}

static void	do_ops(t_data **data, t_stack *commands)
{
	t_stack	*tmp;
	void	(*pop[11])(void);

	tmp = commands;
	init_pop(pop);
	while (tmp && (tmp = tmp->previous))
	{
		if ((*data)->options & 1)
		{
			print((*data)->a, (*data)->a, (*data)->b, (*data)->b);
			pop[tmp->content]();
		}
		(*data)->op[tmp->content](data);
		if (tmp == commands)
			break ;
	}
	if ((*data)->options & 1)
		print((*data)->a, (*data)->a, (*data)->b, (*data)->b);
	if ((*data)->options & (1 << 1))
		ft_printf("count: %zu\n\n", (*data)->n);
	(check_res(data)) ? ft_printf("OK\n") : ft_printf("KO\n");
}

static void	save_output(t_data **data, t_stack **commands)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!line || !check_op(line, commands) || !*commands)
		{
			stackdel(commands);
			ft_strdel(&line);
			quit(data);
		}
		ft_strdel(&line);
	}
}

int			main(int ac, char **av)
{
	int		flags;
	t_stack	*commands;
	t_data	*data;

	if (ac < 2)
		return (0);
	commands = NULL;
	if (!(data = init_data()))
		quit(&data);
	flags = check_flags(av, &data);
	data->size = ac - 1 - flags;
	if (!(data->res = (int*)malloc(sizeof(*data->res) * data->size)))
		quit(&data);
	while (ac-- > 1 + flags)
	{
		check_arg(av[ac], &data);
		data->res[ac - (1 + flags)] = data->a->content;
	}
	quicksort_tab(data->res, 0, data->size - 1);
	check_tab(&data, data->size);
	save_output(&data, &commands);
	do_ops(&data, commands);
	stackdel(&commands);
	delete_data(&data);
	return (0);
}
