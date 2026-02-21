/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* stack_utils2.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/02/21 18:44:17 by jeongkim          #+#    #+#             */
/* Updated: 2026/02/21 18:44:17 by jeongkim         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}