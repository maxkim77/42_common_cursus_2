#include "../../inc/push_swap.h"

// 1. 여기에 함수 프로토타입을 미리 선언 (중요!)
static void rotate(t_stack_node **stack);

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (print) // !print였던 부분을 실무적으로 수정
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (print)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        ft_printf("rr\n");
}

// 2. 실제 구현은 아래에 있어도 됨
static void rotate(t_stack_node **stack)
{
    t_stack_node    *old_top;
    t_stack_node    *last_node;

    if (!*stack || !(*stack)->next)
        return ;
    old_top = *stack;
    last_node = find_last(*stack);
    *stack = old_top->next;
    (*stack)->prev = NULL;
    last_node->next = old_top;
    old_top->prev = last_node;
    old_top->next = NULL;
}