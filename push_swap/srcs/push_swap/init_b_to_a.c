/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:44:07 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 22:44:09 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b_to_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target;
	long			match_idx;

	while (b)
	{
		match_idx = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->nbr > b->nbr && curr_a->nbr < match_idx)
			{
				match_idx = curr_a->nbr;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match_idx == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b_to_a(a, b);
}
