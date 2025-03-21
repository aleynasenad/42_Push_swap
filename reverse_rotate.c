/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:31:18 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:24 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}
