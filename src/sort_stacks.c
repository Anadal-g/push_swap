/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:32:57 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/19 12:59:31 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
    if (!stack)
    {
        printf("La pila está vacía.\n");
        return;
    }

    printf("Estado de la pila:\n");
    printf("Index\tNumber\n");

    while (stack)
    {
        printf("%d\t%d\n", stack->index, stack->number);
        stack = stack->next;
    }
    printf("-----------------------\n");
}

void update_indices(t_stack *stack)
{
    int index = 0;
    
    while (stack)
    {
        stack->index = index;
        stack = stack->next;
        index++;
    }
}

// Establece el nodo objetivo en la pila 'b' para cada nodo de la pila 'a'
void stack_set_target_a(t_stack *main_stack, t_stack *stack_b)
{
    t_stack *target_stack;
    long target_num;

    target_num = LONG_MIN;
    target_stack = stack_b;
    while (target_stack)
    {
        if (target_stack->number < main_stack->number && target_stack->number > target_num)
        {
            target_num = target_stack->number;
            main_stack->target = target_stack;
        }
        target_stack = target_stack->next;
    }
    if (target_num == LONG_MIN)
        main_stack->target = find_max(stack_b);
}
//define el costo
void stack_set_push_cost(t_stack *a, t_stack *b, t_stack *node_a, int *count)
{
    int less_half;

    stack_set_target_a(node_a, b);
    less_half = stack_len(b) - node_a->target->id;
    if (node_a->above_median)
        *count = node_a->id;
    else
        *count = stack_len(a) - node_a->id;
    if (node_a->above_median && node_a->target->above_median)
    {
        if (node_a->target->id > *count)
            *count += (node_a->target->id - *count);
    }
    else if (!node_a->above_median && !node_a->target->above_median)
    {
        if (*count < less_half)
            *count += (less_half - *count);
    }
    else if (node_a->target->above_median)
        *count += node_a->target->id;
    else
        *count += less_half;
}

t_stack *find_min(t_stack *stack)
{
    long min_value;
    t_stack *min_node;
	
	min_value = LONG_MAX;
	min_node = NULL;
    while (stack)
    {
        if (stack->number < min_value)
        {
            min_value = stack->number;
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}

// Ejecuta movimientos para colocar el nodo "cheapest" en la posicion correcta en 'a'
void execute_moves(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*b != cheapest)
    {
        if (cheapest->index <= stack_len(*b) / 2)
            rb(b, true);
        else
            rrb(b, true);
    }
    stack_set_target_a(cheapest, *a);
    while (*a != cheapest->target)
    {
        if (cheapest->target->index <= stack_len(*a) / 2)
            ra(a, true);
        else
            rra(a, true);
    }
    if (cheapest->index <= stack_len(*b) / 2 && cheapest->target->index <= stack_len(*a) / 2)
    {
        while (*b != cheapest && *a != cheapest->target)
            rr(a, b, true);
    }
    else if (cheapest->index > stack_len(*b) / 2 && cheapest->target->index > stack_len(*a) / 2)
    {
        while (*b != cheapest && *a != cheapest->target)
            rrr(a, b, true);
    }
}

t_stack *find_cheapest_move(t_stack *a, t_stack *b)
{
    t_stack *current;
    t_stack *cheapest;
    int min_cost;
    int current_cost;

    min_cost = INT_MAX;
    cheapest = NULL;
    current = b;
    while (current)
    {
        stack_set_push_cost(a, b, current, &current_cost);
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return (cheapest);
}

void sort_end(t_stack **stack_a)
{
    t_stack *min_node;

    min_node = find_min(*stack_a);
    while (*stack_a != min_node)
    {
        if (min_node->index <= stack_len(*stack_a) / 2)
            ra(stack_a, true);
        else
            rra(stack_a, true);
        update_indices(*stack_a);
    }
}
int find_median(t_stack *stack)
{
    int len = stack_len(stack);
    int *values = malloc(sizeof(int) * len);
    t_stack *current = stack;

    if (!values)
    {
        perror("Error en la asignación de memoria");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < len)
    {
        values[i] = current->number;
        current = current->next;
        i++;
    }
    int j;
    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (values[i] > values[j])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
            j++;
        }
        i++;
    }
    int median = values[len / 2];
    free(values);
    return median;
}
void sort_push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;

    while (*stack_b)
    {
        cheapest_node = find_cheapest_move(*stack_a, *stack_b);
        if (!cheapest_node)
        {
            printf("Error: No se pudo encontrar el nodo más barato.\n");
            break;
        }
        execute_moves(stack_a, stack_b, cheapest_node);
        pa(stack_a, stack_b, true);
        printf("pa - Nodo %d movido de B a A\n", (*stack_a)->number);
        update_indices(*stack_a);
        update_indices(*stack_b);
    }
}


void sort_push_b(t_stack **stack_a, t_stack **stack_b)
{
    int median;
    int len;
    int pushed = 0;

    len = stack_len(*stack_a);
    median = find_median(*stack_a);

    while (pushed < len)
    {
        if ((*stack_a)->number < median)
        {
            pb(stack_b, stack_a, true);
            printf("pb - Nodo %d movido a la pila B\n", (*stack_b)->number);
            pushed++;
        }
        else
        {
            ra(stack_a, true);
            printf("ra - Nodo %d movido al final de la pila A\n", (*stack_a)->number);
            pushed++;
        }
        update_indices(*stack_a);
        update_indices(*stack_b);
    }
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    print_stack(*stack_a);
    sort_push_b(stack_a, stack_b);
    sort_three(stack_a);
    sort_push_a(stack_a, stack_b);
    sort_end(stack_a);
    print_stack(*stack_a);
}

