/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:31:16 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/19 16:04:03 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	index_median_check(*stack_a);
	index_median_check(*stack_b);
}
