/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:31:49 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/22 17:23:27 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **st, int out)
{
	t_stack	*tmp;
	
	tmp = (*st)->next;
	(*st)->next = tmp->next;
	tmp->prev = (*st)->prev;
	(*st)->prev = tmp;
	tmp->next = (*st);
	if (out == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **st, int out)
{
	t_stack	*tmp;
	
	tmp = (*st)->next;
	(*st)->next = tmp->next;
	tmp->prev = (*st)->prev;
	(*st)->prev = tmp;
	tmp->next = (*st);
	if (out == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **sta, t_stack **stb)
{
	sa(sta, 0);
	sb(stb, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **sta, t_stack **stb)
{
	(*stb)->prev->next = (*stb)->next;
	(*stb)->next->prev = (*stb)->prev;
	(*stb)->next = (*sta);
	(*stb)->prev = (*sta)->prev;
	(*sta)->prev->next = (*stb);
	(*sta)->prev = (*stb);
	write(1, "pa\n", 3);
}

void	pb(t_stack **sta, t_stack **stb)
{
	(*sta)->prev->next = (*sta)->next;
	(*sta)->next->prev = (*sta)->prev;
	(*sta)->next = (*stb);
	(*sta)->prev = (*stb)->prev;
	(*stb)->prev->next = (*sta);
	(*stb)->prev = (*sta);
	write(1, "pb\n", 3);
}