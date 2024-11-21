/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:07:18 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/20 16:54:40 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	long	num_max;

	max = NULL;
	num_max = INT_MIN;
	while (stack)
	{
		if (stack->number > num_max)
		{
			max = stack;
			num_max = stack->number;
		}
		stack = stack->next;
	}
	return (max);
}


t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	long	num_min;

	min = NULL;
	num_min = INT_MAX;
	while (stack)
	{
		if (stack->number < num_min)
		{
			min = stack;
			num_min = stack->number;
		}
		stack = stack->next;
	}
	return (min);
}
