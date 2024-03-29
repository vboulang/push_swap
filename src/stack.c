/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:36 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/29 10:09:02 by vboulang         ###   ########.fr       */
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
	t_stack *tmp;
	
	tmp = st;
	while (tmp->next)
	{
		//dprintf(1,"%d %d\n", tmp->value, val);
		check_val(tmp->value, val);
		tmp = tmp->next;
	}
	check_val(tmp->value, val);
	return (tmp);
}

t_stack	*last_st(t_stack *st)
{
	t_stack *tmp;
	
	// if (!st)
	// 	return (NULL);
	tmp = st;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}


void	addback_st(t_stack **st, t_stack *new)
{
	t_stack *tmp;

	
	if (*st)
	{
		tmp = last_n_check_st(*st, new->value);
		tmp->next = new;
		new->prev = tmp;
	}
	else
		(*st) = new;
}

void	loop(t_stack **st)
{
	t_stack *tmp;

	tmp = last_st((*st));
	if (!tmp)
	{
		write(1, "END\n", 4);
	}
	(*st)->prev = tmp;
	tmp->next = (*st);
}

int	size_st(t_stack **st)
{
	int	i;
	int	count;
	int ok;
	
	if (!(*st))
		return (0);
	count = 0;
	ok = 1;
	i = (*st)->value;
	while ((*st) && ok)
	{
		count++;
		(*st) = (*st)->next;
		if (*st)
		{
			if ((*st)->value == i)
				ok = 0;
		}
	}
	return (count);
}
