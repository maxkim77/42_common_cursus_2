/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 23:57:44 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		(*dst)->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
