/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:36 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/22 18:13:48 by vboulang         ###   ########.fr       */
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

t_stack	*new_st(int value)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->value = value;
	st->next = NULL;
	st->prev = NULL;
	return (st);
}

t_stack	*last_n_check_st(t_stack *st, int val)
{
	if (!st)
		return (NULL);
	while (st->next)
	{
		// printf("%d %d\n", st->value, val);
		check_val(st->value, val);
		st = st->next;
	}
	check_val(st->value, val);
	return (st);
}

void	loop(t_stack **st)
{
	t_stack *tmp;

	tmp = (*st);
	while ((*st)->next)
		(*st) = (*st)->next;
	tmp->prev = (*st);
	(*st)->next = tmp;
}

void	addback_st(t_stack **st, t_stack *new)
{
	t_stack *tmp;

	if ((*st))
	{
		tmp = last_n_check_st((*st), new->value);
		// printf("%d %d --\n", tmp->value, new->value);
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		//printf("%d\n", new->value);
		(*st) = new;
	}
}
