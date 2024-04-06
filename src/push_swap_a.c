/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:27 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/06 12:15:00 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_in_sta(t_stack **st)
{
	int		i;
	t_stack	*tmp;

	tmp = (*st);
	i = 0;
	while (tmp->id != get_max_id(st))
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(&tmp) / 2)
	{
		while (i-- != 0)
			ra(st, 1);
	}
	else
	{
		while (i++ < size_st(&tmp))
			rra(st, 1);
	}
}

void	place_best_spot_a(t_stack **sta, t_stack **stb)
{
	int		i;
	int		pos;
	int		diff;
	t_stack	*tmp;

	i = 0;
	pos = i;
	tmp = (*sta);
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
	if (pos <= size_st(&tmp) / 2)
	{
		while (pos-- != 0)
			ra(sta, 1);
	}
	else
	{
		while (pos++ < size_st(&tmp))
			rra(sta, 1);
	}
	pa(sta, stb);
}

void	move_a(t_stack **sta, t_stack **stb, int i)
{
	if (i <= size_st(stb) / 2)
	{
		while (i-- != 0)
			rb(stb, 1);
	}
	else
	{
		while (i++ < size_st(stb))
			rrb(stb, 1);
	}
	if ((*stb)->id > get_max_id(sta) || (*stb)->id < get_min_id(sta))
	{
		move_in_sta(sta);
		pa(sta, stb);
	}
	else
		place_best_spot_a(sta, stb);
}

int	calc_move_to_a(t_stack **sta, t_stack **stb, int i)
{
	int	count;

	count = 0;
	if (i <= size_st(stb) / 2)
	{
		while (i-- != 0)
			count++;
	}
	else
	{
		while (i++ < size_st(stb))
			count++;
	}
	if ((*stb)->id > get_max_id(sta) || (*stb)->id < get_min_id(sta))
	{
		search_in_sta(&count, sta, stb);
		count++;
	}
	return (count);
}

void	move_best_a(t_stack **sta, t_stack **stb, int *best)
{
	int	min_i;
	int	i;

	i = 0;
	min_i = -1;
	while (i < size_st(stb))
	{
		if (best[i] < min_i || min_i < 0)
			min_i = i;
		i++;
	}
	move_a(sta, stb, min_i);
}

void	search_in_sta(int *count, t_stack **sta, t_stack **stb)
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
		if (tmp->id - (*stb)->id < diff && tmp->id - (*stb)->id > 0)
		{
			diff = tmp->id - (*stb)->id;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	// while (tmp->id != get_min_id(&tmp))
	// {
	// 	i++;
	// 	tmp = tmp->next;
	// }
	if (pos <= size_st(&tmp) / 2)
	{
		while (pos-- != 0)
			(*count)++;
	}
	else
	{
		while (pos++ < size_st(&tmp))
			(*count)++;
	}
}

void	move_to_a(t_stack **sta, t_stack **stb)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		*best;
	int		i;

	i = 0;
	best = ft_calloc(size_st(stb), sizeof(int));
	tmpa = (*sta);
	tmpb = (*stb);
	best[i] = calc_move_to_a(&tmpb, &tmpa, i);
	i++;
	tmpb = tmpb->next;
	while (i < size_st(stb))
	{
		best[i] = calc_move_to_a(&tmpb, &tmpa, i);
		i++;
	}
	move_best_a(sta, stb, best);
	free(best);
}
