/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:20:18 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 16:12:43 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_stack **sta, t_stack **stb)
{
	pb(sta, stb);
	if (size_st(sta) > 4)
		pb(sta, stb);
	while (size_st(sta) > 3)
	{
		initialize_count(sta);
		initialize_count(stb);
		move_to_b(sta, stb);
	}
	sort_3(sta);
	while (size_st(stb) != 0)
	{
		initialize_count(sta);
		initialize_count(stb);
		move_to_a(sta, stb);
	}
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

void	move_to_b(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*sta);
	while (i < size_st(sta))
	{
		calc_move_to_b(&tmp, stb, i);
		i++;
		get_total(&tmp);
		tmp = tmp->next;
	}
	move_best_b(sta, stb);
}

void	move_to_a(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stb);
	while (i < size_st(stb))
	{
		calc_move_to_a(sta, &tmp, i);
		i++;
		get_total(&tmp);
		tmp = tmp->next;
	}
	move_best_a(sta, stb);
}
