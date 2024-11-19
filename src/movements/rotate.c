/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:59 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/19 11:28:19 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *last_node;

    if (!*stack || !(*stack)->next)
        return;

    last_node = find_last(*stack);
    last_node->next = *stack;
    (*stack)->prev = last_node;

    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->next = NULL;
}


void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		printf("ra\n");
	update_indices(*a);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		printf("rr\n");
}
