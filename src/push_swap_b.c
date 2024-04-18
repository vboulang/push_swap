/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:12 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 16:29:13 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	calc_best_spot_b(t_stack **sta, t_stack **stb)
{
	int		i;
	int		diff;
	int		pos;
	t_stack	*tmp;

	i = 1;
	pos = 0;
	tmp = (*stb);
	if ((*sta)->id - tmp->id < 0)
		diff = 1000;
	else
		diff = (*sta)->id - tmp->id;
	tmp = tmp->next;
	while (tmp->id != (*stb)->id)
	{
		if ((*sta)->id - tmp->id < diff && (*sta)->id - tmp->id > 0)
		{
			diff = (*sta)->id - tmp->id;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (pos <= size_st(&tmp) / 2)
	{
		while (pos-- != 0)
			(*sta)->rb++;
	}
	else
	{
		while (pos++ < size_st(&tmp))
			(*sta)->rrb++;
	}
	(*sta)->total++;
}

void	move_b(t_stack **sta, t_stack **stb, t_stack **tmp)
{
	while ((*tmp)->ra > 0)
	{
		ra(sta, 1);
		(*tmp)->ra--;
	}
	while ((*tmp)->rb > 0)
	{
		rb(stb, 1);
		(*tmp)->rb--;
	}
	while ((*tmp)->rr > 0)
	{
		rr(sta, stb);
		(*tmp)->rr--;
	}
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
	pb(sta, stb);
}

void	calc_move_to_b(t_stack **sta, t_stack **stb, int i)
{
	if (i <= size_st(sta) / 2)
	{
		while (i-- != 0)
			(*sta)->ra++;
	}
	else
	{
		while (i++ < size_st(sta))
			(*sta)->rra++;
	}
	if ((*sta)->id > get_max_id(stb) || (*sta)->id < get_min_id(stb))
	{
		search_in_stb(sta, stb);
		(*sta)->total++;
	}
	else
		calc_best_spot_b(sta, stb);
}

void	move_best_b(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		min_id;

	tmp = (*sta);
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
	move_b(sta, stb, &tmp);
}

void	search_in_stb(t_stack **sta, t_stack **stb)
{
	int		i;
	int		diff;
	int		pos;
	t_stack	*tmp;

	i = 0;
	pos = i;
	tmp = (*stb);
	diff = (*sta)->id - tmp->id;
	tmp = tmp->next;
	while (tmp->id != (*stb)->id)
	{
		if ((*sta)->id - tmp->id < diff && (*sta)->id - tmp->id > 0)
		{
			diff = (*sta)->id - tmp->id;
			pos = i;// + 1;
		}
		tmp = tmp->next;
		i++;
	}
	register_ra(sta, &tmp, pos);
}
