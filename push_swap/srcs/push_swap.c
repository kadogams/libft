/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:44 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/25 11:18:15 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main function of the Push_swap program.
** Flow of the program:
**  - check command line arguments
**  - quicksort on an int array to have a presorted array, in order to find
**    the median values of the partitions faster during the main algorithm
**  - backtracking on the whole set of values to see if can be solved in 8
**    or less moves
**  - start a divide and conquer algorithm based on medians, with a backtracking
**    when a partition contains 5 or less elements, in order to sort them with
**    the minimum possible instructions
*/

static void	remove_reverse_op(t_data **data)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*data)->log)
		tmp = (*data)->log->previous;
	while (tmp)
	{
		if (tmp && tmp != tmp->previous && (*data)->op[tmp->content] ==
				(*data)->rop[tmp->previous->content])
		{
			tmp = tmp->previous;
			stackdelone(&tmp);
			stackdelone(&tmp);
			(*data)->n -= 2;
			if (tmp == (*data)->log->previous)
				tmp = tmp->previous;
		}
		else
			tmp = tmp->previous;
		if (tmp == (*data)->log)
			break ;
	}
}

static void	replace_double_op(t_data **data, t_stack **tmp)
{
	int	check;

	check = 0;
	if (((*tmp)->content == 0 && (*tmp)->previous->content == 1)
			|| ((*tmp)->content == 1 && (*tmp)->previous->content == 0))
		check = 2;
	else if (((*tmp)->content == 5 && (*tmp)->previous->content == 6)
			|| ((*tmp)->content == 6 && (*tmp)->next->content == 5))
		check = 7;
	else if (((*tmp)->content == 8 && (*tmp)->previous->content == 9)
			|| ((*tmp)->content == 9 && (*tmp)->previous->content == 8))
		check = 10;
	if (check)
	{
		*tmp = (*tmp)->previous;
		stackdelone(tmp);
		(*tmp)->content = check;
		(*data)->n--;
	}
}

static void	print_op(t_data **data)
{
	t_stack	*tmp;
	void	(*pop[11])(void);

	tmp = NULL;
	init_pop(pop);
	remove_reverse_op(data);
	if ((*data)->log)
		tmp = (*data)->log->previous;
	while (tmp)
	{
		if (tmp != (*data)->log)
			replace_double_op(data, &tmp);
		pop[tmp->content]();
		tmp = tmp->previous;
		if (tmp == (*data)->log->previous)
			break ;
	}
}

static void	solve(t_data **data)
{
	(*data)->med = (*data)->res;
	(*data)->min = (*data)->res;
	(*data)->max = (*data)->res + (*data)->size - 1;
	while (!omae_wa_mou_shindeiru(data, 0) && (*data)->t < 9)
		(*data)->t++;
	if ((*data)->t > 8)
		sort_a(data, (*data)->size, (*data)->size / 2);
}

int			main(int ac, char **av)
{
	int		flags;
	t_data	*data;

	if (ac < 2)
		return (0);
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
	solve(&data);
	print_op(&data);
	delete_data(&data);
	return (0);
}
