/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:23:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 14:02:33 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_id(t_stack **st)
{
	int		start;
	int		ok;
	int		min;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->id;
	min = tmp->id;
	while (ok)
	{
		if (tmp->id < min)
		{
			min = tmp->id;
		}
		tmp = tmp->next;
		if (tmp->id == start)
			ok = 0;
	}
	return (min);
}

void	initialize_count(t_stack **st)
{
	t_stack *tmp;

	tmp = (*st);
	tmp->ra = 0;
	tmp->rb = 0;
	tmp->rr = 0;
	tmp->rra = 0;
	tmp->rrb = 0;
	tmp->rrr = 0;
	tmp->total = 0;
	tmp = tmp->next;
	while (tmp->id != (*st)->id)
	{
		tmp->ra = 0;
		tmp->rb = 0;
		tmp->rr = 0;
		tmp->rra = 0;
		tmp->rrb = 0;
		tmp->rrr = 0;
		tmp->total = 0;
		tmp = tmp->next;
	}
}

void	get_total(t_stack **st)
{
	
	while ((*st)->ra > 0 && (*st)->rb > 0)
	{
		(*st)->rr++;
		(*st)->ra--;
		(*st)->rb--;
		(*st)->total++;
	}
	while ((*st)->rra > 0 && (*st)->rrb > 0)
	{
		(*st)->rrr++;
		(*st)->rra--;
		(*st)->rrb--;
		(*st)->total++;
	}
	(*st)->total += ((*st)->ra + (*st)->rb + (*st)->rra + (*st)->rrb);
	//dprintf(1, "%d %d %d %d %d %d %d\n", (*st)->ra, (*st)->rb, (*st)->rr, (*st)->rra, (*st)->rrb, (*st)->rrr, (*st)->total);
}

void	set_id(t_stack **st)
{
	int		id;
	t_stack	*tmp;

	id = 0;
	while (id < size_st(st))
	{
		tmp = get_min(st);
		tmp->id = id;
		id++;
	}
}

int	get_max_id(t_stack **st)
{
	int		start;
	int		ok;
	int		max;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->id;
	max = tmp->id;
	while (ok)
	{
		if (tmp->id > max)
		{
			max = tmp->id;
		}
		tmp = tmp->next;
		if (tmp->id == start)
			ok = 0;
	}
	return (max);
}
