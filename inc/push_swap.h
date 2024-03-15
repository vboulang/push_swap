/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:17:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/15 16:35:55 by vboulang         ###   ########.fr       */
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
}	t_stack;

void	addback_st(t_stack *st, t_stack *new, int *order_check);
void	new_st(t_stack *st, int value);

void	create_stack(char **strs, t_stack *st);
void 	load_args(int ac, char **av, t_stack *st);
int		main(int argc, char **argv);

#endif