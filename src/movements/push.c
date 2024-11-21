/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:09 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/19 17:05:08 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **dest, t_stack **source)
{
	t_stack	*push_node;

	if (!*source)
		return ;
	push_node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	push_node->next = *dest;
	if (*dest)
		(*dest)->prev = push_node;
	*dest = push_node;
	push_node->prev = NULL;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		printf("pa\n");
	
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		printf("pb\n");
}
