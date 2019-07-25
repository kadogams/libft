/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:30:33 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:50:56 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"
# include <fcntl.h>
# include <limits.h>

/*
** Macros corresponding the the index of the operations in
** the array of pointers
*/

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define MAX_OP 10

typedef struct	s_stack
{
	int				content;
	struct s_stack	*previous;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_data
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*log;
	int				*res;
	int				*med;
	int				*min;
	int				*max;
	unsigned int	size;
	size_t			n;
	size_t			t;
	int				(*op[11])(struct s_data **data);
	int				(*rop[11])(struct s_data **data);
	int				(*check_op[11])(struct s_data **data);
	int				options;
}				t_data;

int				backtrack_a(t_data **data, unsigned int nb, int rot_a, int rot_b);
int				backtrack_b(t_data **data, unsigned int nb, int rot_a, int rot_b);
int				check_a(t_data **data);
int				check_a2(t_data **data);
int				check_b(t_data **data);
int				check_b2(t_data **data);
int				check_ab(t_data **data);
int				check_arg(char *s, t_data **data);
int				check_flags(char **av, t_data **data);
void			check_tab(t_data **data, unsigned int n);
int				deal_with_it(t_data **data);
void			delete_data(t_data **data);
void			sort_a(t_data **data, unsigned int n, int median);
void			sort_a2(t_data **data, unsigned int n, int median, int way);
void			sort_b(t_data **data, unsigned int n, int median, int way);
void			init_backtrack_a(t_data **data, unsigned int n, int way);
void			init_check_op(int (*check_op[11])(t_data **data));
t_data			*init_data(void);
void			init_op(int (*op[11])(t_data **data),
						int (*rop[11])(t_data **data));
void			init_pop(void (*pop[11])(void));
int				omae_wa_mou_shindeiru(t_data **data, unsigned int nb);
void			print(t_stack *a, t_stack *a_head, t_stack *b, t_stack *b_head);
void			quicksort_tab(int *res, int l, int h);
void			quit(t_data **data);
void			reverse_op(t_data **data, int i, unsigned int *nb);
int				sorted_or_what(t_data **data, unsigned int size);
int				to_do_or_not_to_do(t_data **data, int i);

void			stackdel(t_stack **stack);
void			stackdelone(t_stack **stack);
void			stacknew(t_stack **head, int content);

void			swap(t_stack **head);
void			push(t_stack **dst_head, t_stack **src_head);
void			rotate(t_stack **head);
void			rrotate(t_stack **head);

int				sa(t_data **data);
int				sb(t_data **data);
int				ss(t_data **data);
int				pa(t_data **data);
int				pb(t_data **data);
int				ra(t_data **data);
int				rb(t_data **data);
int				rr(t_data **data);
int				rra(t_data **data);
int				rrb(t_data **data);
int				rrr(t_data **data);

void			put_sa(void);
void			put_sb(void);
void			put_ss(void);
void			put_pa(void);
void			put_pb(void);
void			put_ra(void);
void			put_rb(void);
void			put_rr(void);
void			put_rra(void);
void			put_rrb(void);
void			put_rrr(void);

#endif
