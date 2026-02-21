/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 14:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

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
		result = (result * 10) + (*s++ - '0');
	return (result * sign);
}

static void	init_node(t_stack_node *node, int n)
{
	node->nbr = n;
	node->index = 0;
	node->push_cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		free_errors(stack);
	init_node(node, n);
	if (!*stack)
		*stack = node;
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}