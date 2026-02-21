#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;

	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}