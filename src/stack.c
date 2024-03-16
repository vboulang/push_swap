/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:36 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/16 13:56:24 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	new_st(t_stack *st, int value)
{
	st->value = value;
	st->next = NULL;
	st->prev = NULL;

}

void	addback_st(t_stack *st, t_stack *new, int *order_check)
{
	t_stack *tmp;

	tmp = st;
	while (tmp->next)
	{
		printf("%d %d\n", tmp->value, new->value);
		if (tmp->value == new->value)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (tmp->value < new->value)
			*order_check = 1;
		else
			*order_check = 0;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}
