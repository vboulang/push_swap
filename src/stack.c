/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:36 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/26 16:36:33 by vincent          ###   ########.fr       */
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

	dprintf(1, "Hi! I am new here!\n");
	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->value = value;
	st->next = NULL;
	st->prev = NULL;
	dprintf(1, "CREATED\n");
	return (st);
}

t_stack	*last_n_check_st(t_stack *st, int val)
{
	t_stack *tmp;
	
	tmp = st;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		dprintf(1,"%d %d\n", tmp->value, val);
		check_val(tmp->value, val);
		tmp = tmp->next;
	}
	dprintf(1, "%d\n", tmp->next->value);
	check_val(tmp->value, val);
	return (tmp);
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

	if (*st)
	{
		tmp = last_n_check_st(*st, new->value);
		dprintf(1,"%d %d --\n", tmp->value, new->value);
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		dprintf(1,"%d\n", new->value);
		(*st) = new;
	}
}
