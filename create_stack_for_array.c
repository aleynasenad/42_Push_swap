/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_for_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:34:47 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/20 18:39:02 by aldurmaz         ###   ########.fr       */
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

void	create_stack_for_array(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	long long	number;

	i = 0;
	while (i < argc)
	{
		if (is_valid_number(argv[i]))
			error_and_exit2 (stack_a, argv);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_and_exit2 (stack_a, argv);
		if (check_duplicates(*stack_a, (int)number))
			error_and_exit2 (stack_a, argv);
		add_node(stack_a, (int)number);
		i++;
	}
	if (argc == 0)
	{
		error_and_exit2(stack_a, argv);
	}
}

void	split_args(int argc, char **argv, t_stack **stack_a)
{
	char	**new_argv;
	int		new_argc;

	(void)argc;
	new_argv = NULL;
	new_argv = ft_split(argv[1], ' ');
	if (!new_argv)
		return ;
	new_argc = 0;
	while (new_argv[new_argc])
		new_argc++;
	create_stack_for_array(new_argc, new_argv, stack_a);
	free_memory(new_argv);
}

void	free_memory(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
