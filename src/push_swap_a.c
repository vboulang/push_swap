/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:27 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/19 10:54:00 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	calc_best_spot_a(t_stack **sta, t_stack **stb)
{
	int		i;
	int		pos;
	int		diff;
	t_stack	*tmp;

	i = 1;
	pos = 0;
	tmp = (*sta);
	if (tmp->id - (*stb)->id < 0)
		diff = 1000;
	else
		diff = tmp->id - (*stb)->id;
	tmp = tmp->next;
	while (tmp->id != (*sta)->id)
	{
		if (tmp->id - (*stb)->id < diff && tmp->id - (*stb)->id > 0)
		{
			diff = tmp->id - (*stb)->id;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	register_ra(stb, &tmp, pos);
	(*stb)->total++;
}

void	move_a(t_stack **sta, t_stack **stb, t_stack **tmp)
{
	do_r_moves(sta, stb, tmp);
	while ((*tmp)->rra > 0)
	{
		rra(sta, 1);
		(*tmp)->rra--;
	}
	while ((*tmp)->rrb > 0)
	{
		rrb(stb, 1);
		(*tmp)->rrb--;
	}
	while ((*tmp)->rrr > 0)
	{
		rrr(sta, stb);
		(*tmp)->rrr--;
	}
	pa(sta, stb);
}

void	calc_move_to_a(t_stack **sta, t_stack **stb, int i)
{
	register_rb(stb, stb, i);
	if ((*stb)->id > get_max_id(sta) || (*stb)->id < get_min_id(sta))
	{
		search_in_sta(sta, stb);
		(*stb)->total++;
	}
	else
		calc_best_spot_a(sta, stb);
}

void	move_best_a(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		min_id;

	tmp = (*stb);
	i = 0;
	min = tmp->total;
	min_id = tmp->id;
	while (i < size_st(sta))
	{
		if (tmp->total < min)
		{
			min = tmp->total;
			min_id = tmp->id;
		}
		i++;
		tmp = tmp->next;
	}
	while (tmp->id != min_id)
		tmp = tmp->next;
	move_a(sta, stb, &tmp);
}

void	search_in_sta(t_stack **sta, t_stack **stb)
{
	int		i;
	int		diff;
	int		pos;
	t_stack	*tmp;

	tmp = (*sta);
	diff = tmp->id - (*stb)->id;
	tmp = tmp->next;
	i = 0;
	pos = i;
	while (tmp->id != (*sta)->id)
	{
		if (tmp->id - (*stb)->id < diff)
		{
			diff = tmp->id - (*stb)->id;
			pos = i + 1;
		}
		i++;
		tmp = tmp->next;
	}
	register_ra(stb, &tmp, pos);
}
