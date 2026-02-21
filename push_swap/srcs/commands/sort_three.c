/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:42:23 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/22 00:30:56 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest;

	if (!a || !*a)
		return ;
	highest = find_max(*a);
	if (highest == *a)
		ra(a, true);
	else if ((*a)->next == highest)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}
