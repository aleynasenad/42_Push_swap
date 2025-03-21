/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:42:36 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/20 18:43:17 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] > '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicates(t_stack *stack_a, int number)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->number == number)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_and_exit(t_stack **stack_a)
{
	free_stacks(stack_a);
	ft_printf("Error\n");
	exit (1);
}

void	error_and_exit2(t_stack **stack_a, char **argv)
{
	free_memory(argv);
	error_and_exit(stack_a);
}
