/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/06 12:19:01 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_id(t_stack **st)
{
	int		start;
	int		ok;
	int		min;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->id;
	min = tmp->id;
	while (ok)
	{
		if (tmp->id < min)
		{
			min = tmp->id;
		}
		tmp = tmp->next;
		if (tmp->id == start)
			ok = 0;
	}
	return (min);
}

t_stack	*get_min(t_stack **st)
{
	int		start;
	int		ok;
	t_stack	*min;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->value;
	min = NULL;
	while (ok)
	{
		if (tmp->id == -1 && min)
		{
			if (tmp->value < min->value)
				min = tmp;
		}
		else if (tmp->id == -1 && !min)
			min = tmp;
		tmp = tmp->next;
		if (tmp->value == start)
			ok = 0;
	}
	return (min);
}

void	set_id(t_stack **st)
{
	int		id;
	t_stack	*tmp;

	id = 0;
	while (id < size_st(st))
	{
		tmp = get_min(st);
		tmp->id = id;
		id++;
	}
}

int	get_max_id(t_stack **st)
{
	int		start;
	int		ok;
	int		max;
	t_stack	*tmp;

	ok = 1;
	tmp = (*st);
	start = tmp->id;
	max = tmp->id;
	while (ok)
	{
		if (tmp->id > max)
		{
			max = tmp->id;
		}
		tmp = tmp->next;
		if (tmp->id == start)
			ok = 0;
	}
	return (max);
}

void	sort_3(t_stack **st)
{
	if (get_max_id(st) == (*st)->id)
	{
		if (get_min_id(st) == (*st)->next->id)
			ra(st, 1);
		else
		{
			sa(st, 1);
			rra(st, 1);
		}
	}
	else if (get_min_id(st) == (*st)->id)
	{
		if (get_max_id(st) == (*st)->next->id)
		{
			sa(st, 1);
			ra(st, 1);
		}
	}
	else
	{
		if (get_min_id(st) == (*st)->next->id)
			sa(st, 1);
		else
			rra(st, 1);
	}
}

void	place_min_top(t_stack **sta)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*sta);
	while (tmp->id != get_min_id(sta))
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(sta) / 2)
	{
		while (i-- != 0)
			ra(sta, 1);
	}
	else
	{
		while (i++ < size_st(sta))
			rra(sta, 1);
	}
}

void	sort_big(t_stack **sta, t_stack **stb)
{
	pb(sta, stb);
	if (size_st(sta) > 4)
		pb(sta, stb);
	if (size_st(stb) == 2)
	{
		if ((*stb)->id < (*stb)->next->id)
			sb(stb, 1);
	}
	while (size_st(sta) > 3)
		move_to_b(sta, stb);
	sort_3(sta);
	while (size_st(stb) != 0)
		move_to_a(sta, stb);
	place_min_top(sta);
}

void	sort_2(t_stack **st)
{
	if (get_max_id(st) == (*st)->id)
		ra(st, 1);
}

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

void	print_value(t_stack **st)
{
	int	i;
	int	ok;

	ok = 1;
	i = (*st)->value;
	while ((*st)->next && ok)
	{
		dprintf(1, "%d\n", (*st)->value);
		(*st) = (*st)->next;
		if ((*st)->value == i)
			ok = 0;
	}
}

void	print_value_rev(t_stack **st)
{
	int	i;
	int	ok;

	ok = 1;
	i = (*st)->value;
	while ((*st)->prev && ok)
	{
		dprintf(1, "%d\n", (*st)->value);
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
		set_id(&stack_a);
		push_swap(&stack_a, &stack_b);
		dprintf(1, "\nstack a\n");
		print_value(&stack_a);
		if (stack_b)
		{
			dprintf(1, "\nstack b\n");
			print_value(&stack_b);
		}
	}
	return (0);
}
