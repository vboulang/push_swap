/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:12 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/11 20:43:34 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_in_stb(t_stack **st)
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
			rb(st, 1);
	}
	else
	{
		while (i++ < size_st(&tmp))
			rrb(st, 1);
	}
}

void	place_best_spot_b(t_stack **sta, t_stack **stb)
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
			rb(stb, 1);
	}
	else
	{
		while (pos++ < size_st(&tmp))
			rrb(stb, 1);
	}
	pb (sta, stb);
}

void	move_b(t_stack **sta, t_stack **stb, int i)
{
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
	// if ((*sta)->id > (*stb)->id && (*sta)->id < (*stb)->prev->id)
	// 	pb(sta, stb);
	// else 
	if ((*sta)->id > get_max_id(stb) || (*sta)->id < get_min_id(stb))
	{
		move_in_stb(stb);
		pb(sta, stb);
	}
	else
		place_best_spot_b(sta, stb);
}

int	calc_move_to_b(t_stack **sta, t_stack **stb, int i)
{
	int	count;

	count = 0;
	if (i <= size_st(sta) / 2)
	{
		while (i-- != 0)
			count++;
	}
	else
	{
		while (i++ < size_st(sta))
			count++;
	}
	if ((*sta)->id > get_max_id(stb) || (*sta)->id < get_min_id(stb))
	{
		search_in_stb(&count, sta, stb);
		count++;
	}
	return (count);
}

void	move_best_b(t_stack **sta, t_stack **stb, int *best)
{
	int	min_i;
	int	i;

	i = 0;
	min_i = -1;
	while (i < size_st(sta))
	{
		if (best[i] < min_i || min_i < 0)
			min_i = i;
		i++;
	}
	move_b(sta, stb, min_i);
}

void	search_in_stb(int *count, t_stack **sta, t_stack **stb)
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
			pos = i + 1;
		}
		tmp = tmp->next;
		i++;
	}
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

void	move_to_b(t_stack **sta, t_stack **stb)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		*best;
	int		i;

	i = 0;
	best = ft_calloc(size_st(sta), sizeof(int));
	tmpa = (*sta);
	tmpb = (*stb);
	best[i] = calc_move_to_b(&tmpa, &tmpb, i);
	i++;
	tmpa = tmpa->next;
	while (i < size_st(sta))
	{
		best[i] = calc_move_to_b(&tmpa, &tmpb, i);
		i++;
	}
	move_best_b(sta, stb, best);
	free(best);
}
