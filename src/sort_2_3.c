/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:20:15 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/26 13:38:46 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack **st)
{
	if (get_max_id(st) == (*st)->id)
	{
		if (get_min_id(st) == (*st)->next->id)
			ra(st, 1);
		else
		{
			sa(st, 1);
			rra(st, 1);
		}
	}
	else if (get_min_id(st) == (*st)->id)
	{
		if (get_max_id(st) == (*st)->next->id)
		{
			sa(st, 1);
			ra(st, 1);
		}
	}
	else
	{
		if (get_min_id(st) == (*st)->next->id)
			sa(st, 1);
		else
			rra(st, 1);
	}
}

void	sort_2(t_stack **st)
{
	if (get_max_id(st) == (*st)->id)
		ra(st, 1);
}

void	loop(t_stack **st)
{
	t_stack	*tmp;

	tmp = last_st((*st));
	(*st)->prev = tmp;
	tmp->next = (*st);
}
