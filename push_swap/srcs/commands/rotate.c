/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 00:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack_node **stack);

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*old_top;
	t_stack_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old_top = *stack;
	last_node = find_last(*stack);
	*stack = old_top->next;
	(*stack)->prev = NULL;
	last_node->next = old_top;
	old_top->prev = last_node;
	old_top->next = NULL;
}
