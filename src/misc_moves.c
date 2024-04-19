/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:30:45 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/19 12:31:23 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb_in(t_stack **tmp, t_stack **stb)
{
	(*tmp)->next = (*stb);
	(*tmp)->prev = (*stb)->prev;
	(*stb)->prev->next = (*tmp);
	(*stb)->prev = (*tmp);
	(*stb) = (*stb)->prev;
}

void	register_rb(t_stack **st, t_stack **tmp, int pos)
{
	if (pos <= size_st(tmp) / 2)
	{
		while (pos-- != 0)
			(*st)->rb++;
	}
	else
	{
		while (pos++ < size_st(tmp))
			(*st)->rrb++;
	}
}

void	register_ra(t_stack **st, t_stack **tmp, int pos)
{
	if (pos <= size_st(tmp) / 2)
	{
		while (pos-- != 0)
			(*st)->ra++;
	}
	else
	{
		while (pos++ < size_st(tmp))
			(*st)->rra++;
	}
}

void	do_r_moves(t_stack **sta, t_stack **stb, t_stack **tmp)
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
}
