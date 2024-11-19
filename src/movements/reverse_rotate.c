/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:57 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/19 11:28:25 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *last_node;
    t_stack *before_last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    last_node = *stack;
    while (last_node->next)
    {
        before_last = last_node;
        last_node = last_node->next;
	}
    before_last->next = NULL;
    last_node->prev = NULL;
    last_node->next = *stack;
    (*stack)->prev = last_node;
    *stack = last_node;
}


void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		printf("rra\n");
    update_indices(*a);
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		printf("rrr\n");
}
