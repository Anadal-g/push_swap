/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:59 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/04 12:26:33 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_syntax(char *str)
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);
}

int duplicate (t_stack *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->number == n)
            return (1);
        a = a->next;
    }
    return (0);
}
