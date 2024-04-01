/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:31:49 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/30 13:59:55 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **st, int out)
{
	t_stack	*tmp;

	if (size_st(st) > 1)
	{
		tmp = (*st)->next;
		tmp->next->prev = (*st);
		(*st)->prev->next = tmp;
		if (size_st(st) > 2)
		{
			tmp->prev = (*st)->prev;
			(*st)->next = tmp->next;
		}
		tmp->next = (*st);
		(*st)->prev = tmp;
		(*st) = (*st)->prev;
		if (out == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack **st, int out)
{
	t_stack	*tmp;

	if (size_st(st) > 1)
	{
		tmp = (*st)->next;
		tmp->next->prev = (*st);
		(*st)->prev->next = tmp;
		if (size_st(st) > 2)
		{
			tmp->prev = (*st)->prev;
			(*st)->next = tmp->next;
		}
		tmp->next = (*st);
		(*st)->prev = tmp;
		(*st) = (*st)->prev;
		if (out == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack **sta, t_stack **stb)
{
	sa(sta, 0);
	sb(stb, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **sta, t_stack **stb) //TODO change to fit pb... And reduce to 25 lines
{
	t_stack	*tmp;

	if ((*stb))
	{
		tmp = (*stb);
		if (size_st(stb) == 1)
			(*stb) = NULL;
		else
			(*stb) = (*stb)->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->next = (*sta);
		tmp->prev = (*sta)->prev;
		(*sta)->prev->next = tmp;
		(*sta)->prev = tmp;
		(*sta) = (*sta)->prev;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	if ((*sta))
	{
		tmp = (*sta);
		if (size_st(sta) == 1)
			(*sta) = NULL;
		else
			(*sta) = (*sta)->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if ((*stb))
		{
			tmp->next = (*stb);
			tmp->prev = (*stb)->prev;
			(*stb)->prev->next = tmp;
			(*stb)->prev = tmp;
			(*stb) = (*stb)->prev;
		}
		else
		{
			(*stb) = tmp;
			tmp->next = tmp;
			tmp->prev = tmp;
		}
		write(1, "pb\n", 3);
	}
}
