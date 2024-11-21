/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:32:57 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/20 18:31:05 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_above_half(t_stack *stack)
{
	int	half;
	int	median;
	int	i;

	i = 1;
	half = stack_len(stack);
	median = half / 2;
	if (half % 2)
		median++;
	while (stack)
	{
		stack->id = i++;
		if (stack->id <= median)
			stack->median = false;
		else
			stack->median = false;
		stack = stack->next;
	}
}

// Ejecuta movimientos para colocar el nodo "cheapest" en la posicion correcta en 'a'
void execute_moves(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*b != cheapest)
    {
        if (cheapest->index <= stack_len(*b) / 2)
            rb(b, false);
        else
            rrb(b, false);
    }
    stack_set_target_a(cheapest, *a);
    while (*a != cheapest->target)
    {
        if (cheapest->target->index <= stack_len(*a) / 2)
            ra(a, false);
        else
            rra(a, false);
    }
    if (cheapest->index <= stack_len(*b) / 2 && cheapest->target->index <= stack_len(*a) / 2)
    {
        while (*b != cheapest && *a != cheapest->target)
            rr(a, b, false);
    }
    else if (cheapest->index > stack_len(*b) / 2 && cheapest->target->index > stack_len(*a) / 2)
    {
        while (*b != cheapest && *a != cheapest->target)
            rrr(a, b, false);
    }
}


void sort_end(t_stack **stack_a)
{
    t_stack *min_node;

    min_node = find_min(*stack_a);
    while (*stack_a != min_node)
    {
        if (min_node->index <= stack_len(*stack_a) / 2)
            ra(stack_a, false);
        else
            rra(stack_a, false);
    }
}

void sort_push_a(t_stack **stack_a, t_stack **stack_b)
{
    int len_stack_b;
    t_stack *target_b;

    len_stack_b = stack_len(*stack_b);
    while (len_stack_b-- > 0)
    {
        stack_above_half(*stack_a);
        stack_above_half(*stack_b);
        target_b = stack_set_target_b(*stack_b, *stack_a);
        while (*stack_a != target_b)
        {
            if (target_b->median)
                ra(stack_a, stack_b);
            else
                rra(stack_a, stack_b);
        }
        pa(stack_a, stack_b, false);
    }
}

void	sort_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_cost;
	int		len_stack_a;

	len_stack_a = stack_len(*stack_a);
	while (len_stack_a-- > 3 && !stack_sorted(*stack_a))
	{
		stack_above_half(*stack_a);
		stack_above_half(*stack_b);
		min_cost = stack_set_min_cost(stack_a, stack_b);
        if (!min_cost)
        {
            printf("Error: min_cost es NULL en sort_push_b. No se pudo encontrar un nodo con costo mínimo.\n");
            return;
        }
		stack_set_top_node(stack_a, stack_b, min_cost);
		pb(stack_a, stack_b, false);
	}
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int len_stack_a;

    len_stack_a = stack_len(*stack_a);
    if (len_stack_a-- > 3 && !stack_sorted(*stack_a))
        pb(stack_a, stack_b, false);
    if (len_stack_a-- > 3 && !stack_sorted(*stack_a))
        pb(stack_a, stack_b, false);
    sort_push_b(stack_a, stack_b);
    sort_three(stack_a);
    sort_push_a(stack_a, stack_b);
    stack_above_half(*stack_a);
    sort_end(stack_a);
}


