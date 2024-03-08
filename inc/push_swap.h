/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:17:01 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/08 13:44:28 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	t_stack	*next;
	t_stack	*prev;
	int		value;
	int		index;
}	t_stack;

#endif