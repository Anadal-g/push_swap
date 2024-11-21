/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:50:18 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/20 18:34:32 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_set_top_node(t_stack **stack_a, t_stack **stack_b, t_stack *min_cost)
{
	if (!min_cost)
    {
        printf("Error: min_cost es NULL en stack_set_top_node\n");
        return;
    }
	if (min_cost->median && min_cost->target->median)
		while (*stack_a != min_cost && *stack_b != min_cost->target)
			rr(stack_a, stack_b, false);
	else if (!min_cost->median && !min_cost->target->median)
		while (*stack_a != min_cost && *stack_b != min_cost->target)
			rrr(stack_a, stack_b, false);
	if (min_cost->median)
		while (*stack_a != min_cost)
			ra(stack_a, false);
	else
		while (*stack_a != min_cost)
			rra(stack_a, false);
	if (min_cost->target->median)
		while (*stack_b != min_cost->target)
			rb(stack_b, false);
	else
		while (*stack_b != min_cost->target)
			rrb(stack_b, false);
}

t_stack	*stack_set_target_b(t_stack *node, t_stack *stack_a)
{
	t_stack	*target_stack;
	long	target_num;

	target_num = LONG_MAX;
	target_stack = stack_a;
	while (target_stack)
	{
		if (target_stack->number > node->number && target_stack->number < target_num)
		{
			target_num = target_stack->number;
			node->target = target_stack;
		}
		target_stack = target_stack->next;
	}
	if (target_num == LONG_MAX)
	{
    node->target = find_min(stack_a);
    if (!node->target)
	{
        printf("Error: No se pudo establecer un target válido para node_b\n");
        return NULL;
    }
}
	return (node->target);
}

// Establece el nodo objetivo en la pila 'b' para cada nodo de la pila 'a'
void	stack_set_target_a(t_stack *main_stack, t_stack *stack_b)
{
	t_stack	*target_stack;
	long	target_num;

	target_num = LONG_MIN;
	target_stack = stack_b;
	while (target_stack)
	{
		if (target_stack->number < main_stack->number
			&& target_stack->number > target_num)
		{
			target_num = target_stack->number;
			main_stack->target = target_stack;
		}
		target_stack = target_stack->next;
	}
	if (target_num == LONG_MIN)
	{
    main_stack->target = find_max(stack_b);
    if (!main_stack->target)
	{
        printf("Error: No se pudo establecer un target válido para node_a\n");
        return;
    }
}
}

t_stack	*stack_set_min_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*min_cost;
	int		count;
	int		min_moves;

	node_a = *stack_a;
	min_moves = INT_MAX;
	min_cost = NULL;
	while (node_a)
	{
		printf("=> {a: %p, b: %p, na: %p}\n", *stack_a, *stack_b, node_a);
		stack_set_push_cost(*stack_a, *stack_b, node_a, &count);
		if (count == 0)
			return (node_a);
		if (count < min_moves)
		{
			min_moves = count;
			min_cost = node_a;
		}
		node_a = node_a->next;
	}
	return (min_cost);
}

//define el costo

void	stack_set_push_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a, int *count)
{
	int	less_half;

	stack_set_target_a(node_a, stack_b);
	printf("\t=> {a: %p, ta: %p}\n", node_a, node_a->target);
	less_half = stack_len(stack_b) - node_a->target->id;
	if (node_a->median)
		*count = node_a->id;
	else
		*count = stack_len(stack_a) - node_a->id;
	if (node_a->median && node_a->target->median)
	{
		if (node_a->target->id > *count)
			*count += (node_a->target->id - *count);
	}
	else if (!node_a->median && !node_a->target->median)
	{
		if (*count < less_half)
			*count += (less_half - *count);
	}
	else if (node_a->target->median)
		*count += node_a->target->id;
	else
		*count += less_half;
}




