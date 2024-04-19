/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:36 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/19 11:18:11 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_st(int value)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->value = value;
	st->next = NULL;
	st->prev = NULL;
	st->id = -1;
	return (st);
}

t_stack	*last_n_check_st(t_stack *st, int val)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp->next)
	{
		check_val(tmp->value, val, &st);
		tmp = tmp->next;
	}
	check_val(tmp->value, val, &st);
	return (tmp);
}

t_stack	*last_st(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	addback_st(t_stack **st, t_stack *new)
{
	t_stack	*tmp;

	if (*st)
	{
		tmp = last_n_check_st(*st, new->value);
		tmp->next = new;
		new->prev = tmp;
	}
	else
		(*st) = new;
}

int	size_st(t_stack **st)
{
	int	i;
	int	count;
	int	ok;

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
