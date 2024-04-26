/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:17:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/26 13:38:42 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				id;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}	t_stack;

//functions in push_swap.c
void	push_swap(t_stack **sta, t_stack **stb);
void	create_stack_split(char **strs, t_stack **st);
void	create_stack_no_split(char **strs, t_stack **st);
void	load_args(int ac, char **av, t_stack **st);
int		main(int argc, char **argv);

//functions in push_swap_a.c
void	calc_best_spot_a(t_stack **sta, t_stack **stb);
void	move_a(t_stack **sta, t_stack **stb, t_stack **tmp);
void	calc_move_to_a(t_stack **sta, t_stack **stb, int i);
void	move_best_a(t_stack **sta, t_stack **stb);
void	search_in_sta(t_stack **sta, t_stack **stb);

//functions in push_swap_b.c
void	calc_best_spot_b(t_stack **sta, t_stack **stb);
void	move_b(t_stack **sta, t_stack **stb, t_stack **tmp);
void	calc_move_to_b(t_stack **sta, t_stack **stb, int i);
void	move_best_b(t_stack **sta, t_stack **stb);
void	search_in_stb(t_stack **sta, t_stack **stb);

//functions in misc.c
void	check_val(int a, int b, t_stack **st);
void	check_arg_split(char **strs, int i, t_stack **st);
void	check_arg_no_split(char **strs, int i, t_stack **st);
int		check_order(t_stack **st);
void	check_int_val(t_stack **st, long val, char **strs); //./

//functions in misc_moves.c
void	pb_in(t_stack **tmp, t_stack **stb);
void	register_rb(t_stack **st, t_stack **tmp, int pos);
void	register_ra(t_stack **st, t_stack **tmp, int pos);
void	do_r_moves(t_stack **sta, t_stack **stb, t_stack **tmp);

//functions in free.c
void	free_stack(t_stack **st);
void	free_all(char **strs);
void	free_and_null(char *str);

//functions in stack.c
t_stack	*new_st(long value);
t_stack	*last_n_check_st(t_stack *st, int val);
t_stack	*last_st(t_stack *st);
void	addback_st(t_stack **st, t_stack *new);
int		size_st(t_stack **st);

//functions in moves_s_p.c
void	sa(t_stack **st, int out);
void	sb(t_stack **st, int out);
void	ss(t_stack **sta, t_stack **stb);
void	pa(t_stack **sta, t_stack **stb);
void	pb(t_stack **sta, t_stack **stb);

//functions in moves_rr.c 
void	rra(t_stack **st, int out);
void	rrb(t_stack **st, int out);
void	rrr(t_stack **sta, t_stack **stb);

//functions in moves_r.c
void	ra(t_stack **st, int out);
void	rb(t_stack **st, int out);
void	rr(t_stack **sta, t_stack **stb);

//functions in id_count.c
int		get_min_id(t_stack **st);
void	initialize_count(t_stack **st);
void	get_total(t_stack **st);
void	set_id(t_stack **st);
int		get_max_id(t_stack **st);

//functions in sort_2_3.c
void	sort_3(t_stack **st);
void	sort_2(t_stack **st);
void	loop(t_stack **st);

//functions in sort_big.c
void	sort_big(t_stack **sta, t_stack **stb);
void	place_min_top(t_stack **sta);
t_stack	*get_min(t_stack **st);
void	move_to_b(t_stack **sta, t_stack **stb);
void	move_to_a(t_stack **sta, t_stack **stb);

#endif