/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:05:20 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/26 13:39:17 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_val(int a, int b, t_stack **st)
{
	if (a == b)
	{
		write(2, "Error\n", 6);
		free_stack(st);
		exit(EXIT_FAILURE);
	}
}

void	check_int_val(t_stack **st, long val, char **strs)
{
	if (val > INT_MAX || val < INT_MIN)
	{
		write(2, "Error\n", 6);
		if ((*st))
			free_stack(st);
		if (strs)
			free_all(strs);
		exit(EXIT_FAILURE);
	}
}

void	check_arg_split(char **strs, int i, t_stack **st)
{
	int	j;

	j = 0;
	while (strs[i][j])
	{
		if ((j == 0 && strs[i][j] == '-') || (ft_isdigit(strs[i][j])))
			j++;
		else
		{
			free_all(strs);
			if ((*st))
				free_stack(st);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	if (--j >= 11)
	{
		free_all(strs);
		if ((*st))
			free_stack(st);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	check_arg_no_split(char **strs, int i, t_stack **st)
{
	int	j;

	(void)st;
	j = 0;
	while (strs[i][j])
	{
		if (j == 0 && strs[i][j] == '-')
			j++;
		else if (ft_isdigit(strs[i][j]))
			j++;
		else
		{
			if ((*st))
				free_stack(st);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
}

int	check_order(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		if (tmp->value == (*st)->value)
			return (1);
	}
	return (1);
}
