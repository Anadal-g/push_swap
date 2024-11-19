/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:00:40 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/18 16:50:20 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_list(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack || !*stack)
        return;

    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL; // Establecer el puntero a NULL después de liberar toda la lista
}


t_stack	*last_node(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*new_node(int id, long num)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	stack->number = num;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}
void add_node_back(t_stack **stack, t_stack *new_node)
{
    t_stack *current;

    if (!stack || !new_node)
    {
        printf("Error: Puntero nulo pasado a add_node_back\n");
        return;
    }
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        current = *stack;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
}


long	ft_atol_ps(char *str)
{
	long	n;
	int		i;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!ft_isdigit(str[i]))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	while (ft_isdigit(str[i]))
		n = (str[i++] - '0') + (n * 10);
	if (!ft_isdigit(str[i]) && str[i])
		ft_putstr_fd("Error\n", STDERR_FILENO);
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (n);
}
