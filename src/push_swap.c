/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/26 13:29:48 by vboulang         ###   ########.fr       */
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

void	create_stack_split(char **strs, t_stack **st)
{
	int		i;
	t_stack	*new;
	long	val;

	i = 0;
	while (strs[i])
	{
		check_arg_split(strs, i, st);
		val = ft_atol(strs[i]);
		check_int_val(st, val, strs);
		new = new_st(val);
		addback_st(st, new);
		i++;
	}
	if (check_order(st))
	{
		free_all(strs);
		if ((*st))
			free_stack(st);
		exit(EXIT_SUCCESS);
	}
	loop(st);
}

void	create_stack_no_split(char **strs, t_stack **st)
{
	int		i;
	t_stack	*new;
	long	val;

	i = 0;
	while (strs[i])
	{
		check_arg_no_split(strs, i, st);
		val = ft_atol(strs[i]);
		check_int_val(st, val, NULL);
		new = new_st(val);
		addback_st(st, new);
		i++;
	}
	if (check_order(st))
	{
		if ((*st))
			free_stack(st);
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
		create_stack_split(strs, st);
		free_all(strs);
	}
	else
		create_stack_no_split(++av, st);
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
		free_stack(&stack_a);
	}
	return (0);
}
