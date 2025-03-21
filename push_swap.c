/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:25:26 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/19 23:31:53 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		split_args(argc, argv, &stack_a);
	}
	else
		create_stack(argc, argv, &stack_a);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			start_sorting(&stack_a, &stack_b);
	}
	free_stacks(&stack_a);
	return (0);
}
