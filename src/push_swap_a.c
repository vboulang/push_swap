/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:27 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 13:47:59 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_in_sta(t_stack **st)
{
	//int		i;
	t_stack	*tmp;

	tmp = (*st);
	//i = 0;
	while (tmp->id != get_min_id(st))
	{
		//i++;
		tmp = tmp->next;
	}
	// if (i <= size_st(&tmp) / 2)
	// {
	// 	while (i-- != 0)
	// 		ra(st, 1);
	// }
	// else
	// {
	// 	while (i++ < size_st(&tmp))
	// 		rra(st, 1);
	// }
}

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
	if (pos <= size_st(&tmp) / 2)
	{
		while (pos-- != 0)
			(*stb)->ra++;
	}
	else
	{
		while (pos++ < size_st(&tmp))
			(*stb)->rra++;
	}
	(*stb)->total++;
}

void	place_best_spot_a(t_stack **sta, t_stack **stb)
{
	//int		i;
	//int		pos;
	int		diff;
	t_stack	*tmp;

	//i = 1;
	//pos = 0;
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
			//pos = i;
		}
	//	i++;
		tmp = tmp->next;
	}
	// if (pos <= size_st(&tmp) / 2)
	// {
	// 	while (pos-- != 0)
	// 		ra(sta, 1);
	// }
	// else
	// {
	// 	while (pos++ < size_st(&tmp))
	// 		rra(sta, 1);
	// }
	pa(sta, stb);
}

void	move_a(t_stack **sta, t_stack **stb, t_stack **tmp)
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
	pa(sta, stb);
}


int	calc_move_to_a(t_stack **sta, t_stack **stb, int i)
{
	int	count;

	count = 0;
	if (i <= size_st(stb) / 2)
	{
		while (i-- != 0)
			(*stb)->rb++;
	}
	else
	{
		while (i++ < size_st(stb))
			(*stb)->rrb++;
	}
	if ((*stb)->id > get_max_id(sta) || (*stb)->id < get_min_id(sta))//check if condition is good
	{
		search_in_sta(sta, stb);
		(*stb)->total++;
	}
	else
		calc_best_spot_a(sta, stb);
	return (count);
}

void	move_best_a(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int	min;
	int	i;
	int	min_id;

	tmp = (*stb);
	i = 0;
	min = tmp->total;
	//dprintf(1, "%d\n", tmp->total);
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
			(*stb)->ra++;
	}
	else
	{
		while (pos++ < size_st(&tmp))
			(*stb)->rra++;
	}
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
