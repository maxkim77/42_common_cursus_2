/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 23:58:06 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*old_top;
	t_stack_node	*new_top;
	t_stack_node	*new_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old_top = *stack;
	new_top = find_last(*stack);
	new_last = new_top->prev;
	if (!new_last)
		return ;
	new_last->next = NULL;
	new_top->next = old_top;
	new_top->prev = NULL;
	old_top->prev = new_top;
	*stack = new_top;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
