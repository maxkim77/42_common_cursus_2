#include "../../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src)
		return ;
	// 1. 소스 스택의 맨 위 노드를 선택 (Pop)
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	// 2. 선택된 노드를 독립시킴
	node_to_push->prev = NULL;
	// 3. 목적지 스택의 맨 앞에 붙임 (Push)
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}