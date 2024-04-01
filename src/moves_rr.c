/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:40:55 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/30 13:58:49 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack **st, int out)
{
	if (*st)
	{
		(*st) = (*st)->prev;
		if (out == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **st, int out)
{
	if (*st)
	{
		(*st) = (*st)->prev;
		if (out == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **sta, t_stack **stb)
{
	rra(sta, 0);
	rrb(stb, 0);
	write(1, "rrr\n", 4);
}
