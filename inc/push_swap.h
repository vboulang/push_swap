/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:17:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/05 16:16:09 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				id;
}	t_stack;

void	print_value(t_stack **st);
void	print_value_rev(t_stack **st);
void	create_stack(char **strs, t_stack **st);
void	load_args(int ac, char **av, t_stack **st);
int		main(int argc, char **argv);

//functions in misc.c
void	check_val(int a, int b);
void	loop(t_stack **st);
void	pb_in(t_stack **tmp, t_stack **stb);

//functions in stack.c
t_stack	*new_st(int value);
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

#endif