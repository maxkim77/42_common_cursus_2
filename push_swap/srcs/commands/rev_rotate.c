#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*old_top;
	t_stack_node	*new_top;
	t_stack_node	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	// 1. 필요한 노드들을 명확하게 변수에 할당
	old_top = *stack;
	new_top = find_last(*stack);
	new_last = new_top->prev;
	// 2. 새로운 끝(꼬리) 형성
	new_last->next = NULL;
	// 3. 새로운 머리(Top) 설정 및 연결
	new_top->next = old_top;
	new_top->prev = NULL;
	old_top->prev = new_top;
	// 4. 스택의 실제 시작점 포인터 갱신
	*stack = new_top;
}

void	rra(t_stack_node **a, bool print) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}