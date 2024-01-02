/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:12:02 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 15:06:11 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	printf("rra\n");
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
// 	else if (argc == 2)
// 		argv = ft_split(argv[1], ' ');//TODO nuevo split
// 	init_stack_a(&a, argv + 1);
// 	if (!stack_sorted(a))//TODO
// 	{
// 		if (stack_len(a) == 2)//TODO
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	return (0);
}