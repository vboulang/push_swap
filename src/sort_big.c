/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:20:18 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/06 12:27:10 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_stack **sta, t_stack **stb)
{
	pb(sta, stb);
	if (size_st(sta) > 4)
		pb(sta, stb);
	if (size_st(stb) == 2)
	{
		if ((*stb)->id < (*stb)->next->id)
			sb(stb, 1);
	}
	while (size_st(sta) > 3)
		move_to_b(sta, stb);
	sort_3(sta);
	while (size_st(stb) != 0)
		move_to_a(sta, stb);
	place_min_top(sta);
}

void	place_min_top(t_stack **sta)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*sta);
	while (tmp->id != get_min_id(sta))
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(sta) / 2)
	{
		while (i-- != 0)
			ra(sta, 1);
	}
	else
	{
		while (i++ < size_st(sta))
			rra(sta, 1);
	}
}

t_stack	*get_min(t_stack **st)
{
	int		start;
	int		ok;
	t_stack	*min;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->value;
	min = NULL;
	while (ok)
	{
		if (tmp->id == -1 && min)
		{
			if (tmp->value < min->value)
				min = tmp;
		}
		else if (tmp->id == -1 && !min)
			min = tmp;
		tmp = tmp->next;
		if (tmp->value == start)
			ok = 0;
	}
	return (min);
}
