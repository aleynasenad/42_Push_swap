/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:29:23 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/19 23:28:44 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atol(const char *s)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
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

static void	add_node(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->number = num;
	new_node->cheapest = 0;
	if (!(*stack_a))
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}	
}

t_stack	*find_last_node(t_stack *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->next)
		stack_a = stack_a->next;
	return (stack_a);
}

void	create_stack(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	long long	number;

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]))
			error_and_exit (stack_a);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_and_exit (stack_a);
		if (check_duplicates(*stack_a, (int)number))
			error_and_exit (stack_a);
		add_node(stack_a, (int)number);
		i++;
	}
}
