/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/29 10:53:12 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	push_swap(t_stack **stack_a, t_stack **stack_b)
// {
	
// }
int		check_order(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while(tmp->next)
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

void load_args(int ac, char **av, t_stack **st)
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

void	print_value(t_stack **st)
{
	int	i;
	int ok;

	ok = 1;
	i = (*st)->value;
	while ((*st)->next && ok)
	{
		dprintf(1,"%d\n", (*st)->value);
		(*st) = (*st)->next;
		if ((*st)->value == i)
			ok = 0;
	}
}

void	print_value_rev(t_stack **st)
{
	int	i;
	int ok;

	ok = 1;
	i = (*st)->value;
	while ((*st)->prev && ok)
	{
		dprintf(1,"%d\n", (*st)->value);
		(*st) = (*st)->prev;
		if ((*st)->value == i)
			ok = 0;
	}
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
		//load_args(argc, ft_split("0 5 9 4", ' '), &stack_b);
		dprintf(1, "\n\n");
		print_value(&stack_a);
		dprintf(1, "\n\n");
		//print_value(&stack_b);
		dprintf(1, "\n\n");
		// rb(&stack_a, 1);
		// print_value(&stack_a);
		// dprintf(1, "\n\n");
		// rrb(&stack_a, 1);
		// print_value(&stack_a);
		// dprintf(1, "\n\n");
		pa(&stack_a, &stack_b);
		dprintf(1, "stack a\n\n");
		print_value(&stack_a);
		dprintf(1, "stack b\n\n");
		print_value(&stack_b);
		dprintf(1, "\n\n");
		// push_swap(&stack_a, &stack_b);
	}
	return (0);
}
