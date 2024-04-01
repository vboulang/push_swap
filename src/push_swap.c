/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:19:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/04/01 17:54:27 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_val(t_stack **st)
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
	int	id;
	t_stack	*tmp;
	
	id = 0;
	while (id < size_st(st))
	{
		tmp = get_min(st);
		tmp->id = id;
		id++;
	}
}

int	get_max(t_stack **st)
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

void	search_in_st(int *count, t_stack **st)
{
	int	i;
	t_stack	*tmp;
	
	tmp = (*st);
	i = 0;
	while (tmp->id != get_max(&tmp))
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(&tmp)/2)
	{
		while (i-- != 0)
			(*count)++;
	}
	else
	{
		while (i++ < size_st(&tmp))
			(*count)++;
	}
}

void	move_in_st(t_stack **st)
{
	int	i;
	t_stack	*tmp;
	
	tmp = (*st);
	i = 0;
	while (tmp->id != get_max(st))
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(&tmp)/2)
	{
		while (i-- != 0)
			rb(st, 1);
	}
	else
	{
		while (i++ < size_st(&tmp))
			rrb(st, 1);
	}
}

void	place_best_spot(t_stack **sta, t_stack **stb)
{
	int		i;
	t_stack	*tmp;
	
	i = 0;
	tmp = (*stb);
	while (tmp->id > (*sta)->id)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size_st(&tmp)/2)
	{
		while (i-- != 0)
			rb(stb, 1);
	}
	else
	{
		while (i++ < size_st(&tmp))
			rrb(stb, 1);
	}
	pb (sta, stb);
}

void	move(t_stack **sta, t_stack **stb, int i)
{
	if (i <= size_st(sta)/2)
	{
		while (i-- != 0)
			ra(sta, 1);
	}
	else
	{
		while (i++ < size_st(sta))
			rra(sta, 1);
	}
	if ((*sta)->id > get_max(stb) || (*sta)->id < get_min_val(stb))
	{
		move_in_st(stb);
		pb(sta, stb);
	}
	else
		place_best_spot(sta, stb);
}

int	calc_move(t_stack **sta, t_stack **stb, int i)
{
	int	count;
	
	count = 0;
	if (i <= size_st(sta)/2)
	{
		while (i-- != 0)
			count++;
	}
	else
	{
		while (i++ < size_st(sta))
			count++;
	}
	if ((*sta)->id > get_max(stb) || (*sta)->id < get_min_val(stb))
	{
		search_in_st(&count, stb);
		count++;
	}
	return (count);
}

void	move_best(t_stack **sta, t_stack **stb, int *best)
{
	int	min_i;
	int	i;
	
	i = 0;
	min_i = -1;
	while (i < size_st(sta))
	{
		if (best[i] < min_i || min_i < 0)
			min_i = i;
		i++;
	}
	move(sta, stb, min_i);
}

void	move_to_b(t_stack **sta, t_stack **stb)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		*best;
	int		i;
	
	i = 0;
	best = ft_calloc(size_st(sta), sizeof(int));
	tmpa = (*sta);
	tmpb = (*stb);
	best[i] = calc_move(&tmpa, &tmpb, i);
	i++;
	tmpa = tmpa->next;
	while (i < size_st(sta))
	{
		best[i] = calc_move(&tmpa, &tmpb, i);
		i++;
	}
	move_best(sta, stb, best);
	free(best);
}

void	sort_big(t_stack **sta, t_stack **stb)
{
	pb(sta, stb);
	pb(sta, stb);
	if ((*stb)->id < (*stb)->next->id)
		sb(stb, 1);
	while (size_st(sta) > 3)
	{
		dprintf(1, "%d \n\n", size_st(sta));
		move_to_b(sta, stb);
	}
	dprintf(1, "test\n");
}

void	push_swap(t_stack **sta, t_stack **stb)
{

	
	//dprintf(1, "amax %d\nbmax %d\nsizea %d\nsizeb %d\n", stats.max_a, stats.max_b, stats.size_a, stats.size_b);
	if (size_st(sta) > 3)
		sort_big(sta, stb);
	// else if (size_st(sta) == 2)
	// 	sort_2();
	// else if (size_st(sta) == 3)
	// 	sort_3();
		//Calculer les mouvements a faire et choisir le meilleur
		//Definir la sequence de mouvements
		//Executer la sequence de mouvement
		//dprintf(1, "amin %d\namax %d\nbmin %d\nbmax %d\nsizea %d\nsizeb %d\n", stats.min_a, stats.max_a, stats.min_b, stats.max_b, stats.size_a, stats.size_b);

	

}

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
		set_id(&stack_a);
		push_swap(&stack_a, &stack_b);
		dprintf(1, "\nstack a\n");
		print_value(&stack_a);
		
		dprintf(1, "\nstack b\n");
		print_value(&stack_b);
	}
	return (0);
}
