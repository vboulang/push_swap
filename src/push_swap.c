/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/15 18:53:19 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	create_stack(char **strs, t_stack *st)
{
	int		i;
	int		order_check;
	t_stack	new;

	i = 0;
	while (strs[i])
	{
		new_st(&new, ft_atoi(strs[i]));
		addback_st(st, &new, &order_check);
		i++;
	}
	if (order_check == 0)
	{
		printf("yo");
		//sort
	}
	//item = ft_lstnew(ft_atoi(split_av[i]))
	//ft_lstadd_back(st, item)
}

void load_args(int ac, char **av, t_stack *st)
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
		create_stack(av, st);
	
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	//t_stack	stack_b;
	
	if (argc >= 2)
	{
		load_args(argc, argv, &stack_a);
		//push_swap(&stack_a, &stack_b);
	}
	else
		printf("Please provide arguments.");
	return (0);
}
