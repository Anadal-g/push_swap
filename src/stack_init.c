/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:20:51 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/20 11:34:22 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

t_stack *init_stack_a(char **argv, int argc)
{
    t_stack *a;
    int i;

    i = 1;
    a = NULL;
    while (i < argc)
    {
        if (!error_syntax(argv[i]))
        {
            long num = ft_atol(argv[i]);
            if (duplicate(a, num))
            {
                ft_putstr_fd("Error: Repeated value\n", STDERR_FILENO);
				free_error(&a);
            }
            add_node_back(&a, new_node(i, num));
        	i++;	
        }
        else
        {
            ft_putstr_fd("Error: Invalid input\n", STDERR_FILENO);
            exit(1);
        }
    }
    return (a);
}
