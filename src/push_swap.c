/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/18 15:44:56 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_stack **sta, t_stack **stb)
{
	if (size_st(sta) > 3)
		sort_big(sta, stb);
	else if (size_st(sta) == 3)
	{
		sort_3(sta);
	}
	else if (size_st(sta) == 2)
		sort_2(sta);
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

void	create_stack(char **strs, t_stack **st)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (strs[i])
	{
		new = new_st(ft_atoi(strs[i]));
		addback_st(st, new);
		i++;
	}
	if (check_order(st))
	{
		//TODO FREE STRUCT
		exit(EXIT_SUCCESS);
	}
	loop(st);
}

void	load_args(int ac, char **av, t_stack **st)
{
	char	**strs;

	if (ac == 2)
	{
		strs = ft_split(av[1], ' ');
		if (!strs)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		create_stack(strs, st);
	}
	else
		create_stack(++av, st);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		load_args(argc, argv, &stack_a);
		set_id(&stack_a);
		push_swap(&stack_a, &stack_b);
		
	}
	return (0);
}
