/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:32:21 by aldurmaz          #+#    #+#             */
/*   Updated: 2025/03/20 18:35:49 by aldurmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*find_last_node(t_stack *stack_a);
t_stack	*biggest_number(t_stack *stack);
t_stack	*lowest_number(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	create_stack(int argc, char **argv, t_stack **stack_a);
void	create_stack_for_array(int argc, char **argv, t_stack **stack_a);
void	split_args(int argc, char **argv, t_stack **stack_a);
void	error_and_exit(t_stack **stack_a);
void	error_and_exit2(t_stack **stack_a, char **argv);
void	free_stacks(t_stack **stack);
void	free_memory(char **argv);
void	start_sorting(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack_a);
void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	index_median_check(t_stack *stack);
void	find_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print);
int		is_valid_number(char *str);
int		check_duplicates(t_stack *stack_a, int number);
int		stack_size(t_stack *stack_a);
bool	is_sorted(t_stack *stack_a);

void	rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
#endif