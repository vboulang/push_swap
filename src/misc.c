/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:05:20 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 16:19:57 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_val(int a, int b)
{
	if (a == b)
	{
		write(2, "Error\n", 6);
		//TODO FREE STACK ALREADY ALLOCATED
		exit(EXIT_FAILURE);
	}
}

void	loop(t_stack **st)
{
	t_stack	*tmp;

	tmp = last_st((*st));
	(*st)->prev = tmp;
	tmp->next = (*st);
}

void	pb_in(t_stack **tmp, t_stack **stb)
{
	(*tmp)->next = (*stb);
	(*tmp)->prev = (*stb)->prev;
	(*stb)->prev->next = (*tmp);
	(*stb)->prev = (*tmp);
	(*stb) = (*stb)->prev;
}

void	register_ra(t_stack **sta, t_stack **tmp, int pos)
{
	if (pos <= size_st(tmp) / 2)
	{
		while (pos-- != 0)
			(*sta)->ra++;
	}
	else
	{
		while (pos++ < size_st(tmp))
			(*sta)->rra++;
	}
}