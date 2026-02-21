#include "../../inc/push_swap.h"

static void	process_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	if (stack_sorted(*a))
		return ;
	len = stack_len(*a);
	if (len == 2)
		sa(a, false);
	else if (len == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**new_argv;

	a = NULL;
	b = NULL;
	new_argv = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (1);
	if (argc == 2)
	{
		new_argv = split(argv[1], ' ');
		if (!new_argv)
			return (1);
		init_stack_a(&a, new_argv);
		free_split(new_argv);
	}
	else
		init_stack_a(&a, argv + 1);
	process_sort(&a, &b);
	free_stack(&a);
	return (0);
}