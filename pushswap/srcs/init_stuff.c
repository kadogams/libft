/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:23:49 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:59:32 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Init an array of function pointers of the operations and their respective
** reverse operations (to cancel them during the backtracking).
*/

void	init_op(int (*op[11])(t_data **data), int (*rop[11])(t_data **data))
{
	op[SA] = sa;
	op[SB] = sb;
	op[SS] = ss;
	op[PA] = pa;
	op[PB] = pb;
	op[RA] = ra;
	op[RB] = rb;
	op[RR] = rr;
	op[RRA] = rra;
	op[RRB] = rrb;
	op[RRR] = rrr;
	rop[SA] = sa;
	rop[SB] = sb;
	rop[SS] = ss;
	rop[PA] = pb;
	rop[PB] = pa;
	rop[RA] = rra;
	rop[RB] = rrb;
	rop[RR] = rrr;
	rop[RRA] = ra;
	rop[RRB] = rb;
	rop[RRR] = rr;
}

/*
** Init an array of function pointers to print the operations history
** on the stdout.
*/

void	init_pop(void (*pop[11])(void))
{
	pop[SA] = put_sa;
	pop[SB] = put_sb;
	pop[SS] = put_ss;
	pop[PA] = put_pa;
	pop[PB] = put_pb;
	pop[RA] = put_ra;
	pop[RB] = put_rb;
	pop[RR] = put_rr;
	pop[RRA] = put_rra;
	pop[RRB] = put_rrb;
	pop[RRR] = put_rrr;
}

/*
** Init an array of function pointers to check if the current operation
** is worth executing.
*/

void	init_check_op(int (*check_op[11])(t_data **data))
{
	check_op[SA] = check_a2;
	check_op[SB] = check_b2;
	check_op[SS] = check_ab;
	check_op[PA] = check_b;
	check_op[PB] = check_a;
	check_op[RA] = check_a2;
	check_op[RB] = check_b2;
	check_op[RR] = check_ab;
	check_op[RRA] = check_a2;
	check_op[RRB] = check_b2;
	check_op[RRR] = check_ab;
}
