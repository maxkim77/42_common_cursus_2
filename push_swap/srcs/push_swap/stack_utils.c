/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 22:43:44 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->nbr < min_node->nbr)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->nbr > max_node->nbr)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
