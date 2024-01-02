/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:25 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 15:14:19 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	bool			median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;

}	t_stack;

//Utils
t_stack	*find_last(t_stack *stack);
//Movimientos
// static void	push(t_stack **dest, t_stack **source);
// static void	swap(t_stack **head);
// static void	rotate(t_stack **stack);
// static void	reverse_rotate(t_stack **stack);


#endif