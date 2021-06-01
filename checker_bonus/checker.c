#include "get_next_line.h"
#include "../mandatory/push_swap.h"

void	use_cmds(t_stack *stack, char *line)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(stack, 0);
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ra(stack, 0);
	if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		rb(stack, 0);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(stack, 0);
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		sa(stack, 0);
	if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		sb(stack, 0);
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		pb(stack, 0);
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		pa(stack, 0);
}

static	void	init(t_stack *stack, char **argv, int argc)
{
	int	j;
	int	i;

	j = 1;
	stack->size = argc - 1;
	if (check_double(argv))
		exit(0);
	if (check_caracters(argv))
		exit(0);
	stack->stackA = ft_calloc(stack->size + 1, sizeof(int));
	stack->stackB = ft_calloc(stack->size + 1, sizeof(int));
	i = -1;
	while (++i < stack->size)
	{
		stack->stackA[i] = ft_atoi(argv[j]);
		if (ft_atoi(argv[j]) == 0)
			stack->stackA[i] = -1;
		j++;
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	stack;

	init(&stack, argv, argc);
	while (get_next_line(STDIN_FILENO, &line))
	{
		use_cmds(&stack, line);
		if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		{
			rrb(&stack, 0);
			rra(&stack, 0);
		}
		if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		{
			rrb(&stack, 0);
			rra(&stack, 0);
		}
	}
	if (if_order(&stack))
		write(1, "\033[1;32m[OK]\n", 15);
	else
		write(1, "\033[1;31m[KO]\n", 13);
}
