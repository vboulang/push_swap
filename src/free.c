/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:29:46 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/19 12:30:21 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	if (tmp->prev)
	{
		tmp->prev->next = NULL;
		tmp->prev = NULL;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
		tmp->prev = NULL;
	}
	free(tmp);
	tmp = NULL;
}

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	i--;
	while (i >= 0)
	{
		free_and_null(strs[i]);
		i--;
	}
	free(strs);
	strs = NULL;
}

void	free_and_null(char *str)
{
	free(str);
	str = NULL;
}
