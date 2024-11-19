/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:25 by anadal-g          #+#    #+#             */
/*   Updated: 2024/11/19 11:29:21 by anadal-g         ###   ########.fr       */
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
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				id;
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				sorted_position;
	
}	t_stack;

typedef struct s_operation
{
    int total_cost;          // Costo total para alinear este nodo en la otra pila
    int rotations_a;         // Número de rotaciones necesarias en la pila 'a'
    int rotations_b;         // Número de rotaciones necesarias en la pila 'b'
    bool rotate_a_reverse;   // Indicador si se necesita una rotación inversa en 'a'
    bool rotate_b_reverse;   // Indicador si se necesita una rotación inversa en 'b'
    t_stack *node;           // Nodo de 'b' que va a ser insertado en 'a'
} t_operation;

//Utils
t_stack	*find_last(t_stack *stack);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	sort_three(t_stack **a);
int		stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	free_list(t_stack **stack);
void ft_putstr_fd(char *s, int fd);
//Error
int		duplicate(t_stack *a, int n);
int		error_syntax(char *str);
void	free_error(t_stack **a);
void	free_stack(t_stack **stack);

//stack_utils
void	add_node_back(t_stack **stack, t_stack *new);
t_stack	*new_node(int id, long num);


//stack_init
t_stack *init_stack_a(char **argv, int argc);

//stack_sorted
bool	stack_sorted(t_stack *stack);

//sort_stack
void sort_stack(t_stack **a, t_stack **b);
void execute_moves(t_stack **a, t_stack **b, t_stack *cheapest);
void update_indices(t_stack *stack);


//moves
//push
void	push(t_stack **dest, t_stack **source);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
//rr
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
//swap
void	swap(t_stack **head);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
//rotate
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

#endif