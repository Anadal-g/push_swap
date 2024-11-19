/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:02 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/18 17:53:08 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_putstr_fd(char *s, int fd)
{
    int i = 0;
    ssize_t res;

    while (s[i])
    {
        res = write(fd, &s[i], 1);
        (void)res;
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
    {
        ft_putstr_fd("Error: No input\n", STDERR_FILENO);
        return (1);
    }
    stack_a = init_stack_a(argv, argc);
    stack_b = NULL;
    if (!stack_sorted(stack_a))
    {
        if (stack_len(stack_a) == 2)
            sa(&stack_a, false);
        else if (stack_len(stack_a) == 3)
            sort_three(&stack_a);
        else
            sort_stack(&stack_a, &stack_b);
    }
    if (stack_a)
        free_list(&stack_a);
    if (stack_b)
        free_list(&stack_b);
    return (0);
}
