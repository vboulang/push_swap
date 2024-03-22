/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/22 18:20:52 by vboulang         ###   ########.fr       */
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
	}
	if (tmp->value > tmp->next->value)
		return (1);
	else
		return (0);
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
		printf("Problems with memory allocation. Abort.");
		exit(EXIT_FAILURE);
		}
		create_stack(strs, st);
	}
	else
		create_stack(++av, st);
}

void	print_value(t_stack **st)
{
	while ((*st)->prev)
	{
		printf("%d\n", (*st)->value);
		(*st) = (*st)->prev;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	if (argc >= 2)
	{
		load_args(argc, argv, &stack_a);
		print_value(&stack_a);
		//push_swap(&stack_a, &stack_b);
	}
	return (0);
}
