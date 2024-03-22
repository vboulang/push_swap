/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:34:28 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/22 16:55:11 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack **st, int out)
{
	(*st) = (*st)->next;
	if (out == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **st, int out)
{
	(*st) = (*st)->next;
	if (out == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **sta, t_stack **stb)
{
	ra(sta, 0);
	rb(stb, 0);
	write(1, "rr\n", 3);
}
