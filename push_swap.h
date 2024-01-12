/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:25 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/11 16:32:23 by anadal-g         ###   ########.fr       */
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
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;

}	t_stack;

//Utils
t_stack	*find_last(t_stack *stack);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	sort_three(t_stack **a);
int		stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);

//Error
int		duplicate(t_stack *a, int n);
int		error_syntax(char *str);
void	free_error(t_stack **a);
void	free_stack(t_stack **stack);
//Movimientos
//PUSH
// static void	push(t_stack **dest, t_stack **source);
// void	pa(t_stack **a, t_stack **b, bool print);
// void	pb(t_stack **b, t_stack **a, bool print);
// //SWAP
// static void	swap(t_stack **head);
// void	sb(t_stack **b, bool print);
void	sa(t_stack **a, bool print);
// void	ss(t_stack **a, t_stack **b, bool print);
// //ROTATE
// static void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
// void	rb(t_stack **b, bool print);
// void	rr(t_stack **a, t_stack **b, bool print);
// //REVERSE_ROTATE
// static void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
// void	rrb(t_stack **b, bool print);
// void	rrr(t_stack **a, t_stack **b, bool print);
//Init
void	init_stack_a(t_stack **a, char **argv);
//Stack_sorted
bool	stack_sorted(t_stack *stack);
//Sort_stacks
void	sort_stacks(t_stack **a, t_stack **b);
//Init A
void	current_index(t_stack *stack);
static void	set_target_a(t_stack *a, t_stack *b);
static void	cost(t_stack *a, t_stack *b);
void	cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);

#endif