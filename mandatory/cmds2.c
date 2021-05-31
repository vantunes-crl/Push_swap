#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	temp = stack->stackA[0];
	if (stack->stackA[1] == 0)
		return ;
	stack->stackA[0] = stack->stackA[1];
	stack->stackA[1] = temp;
	stack->cmd = ft_strjoin(stack->cmd, "sa\n");
}

void	sb(t_stack *stack)
{
	int	temp;

	temp = stack->stackB[find_top_b(stack) + 1];
	stack->stackB[find_top_b(stack) + 1] = stack->stackB[find_top_b(stack) + 2];
	stack->stackB[find_top_b(stack) + 2] = temp;
	stack->cmd = ft_strjoin(stack->cmd, "sb\n");
}

void	pb(t_stack *stack)
{
	int	save;
	int	i;

	save = stack->stackA[0];
	i = 0;
	if (save == 0)
		return ;
	while (i <= stack->size)
	{
		stack->stackA[i] = stack->stackA[i + 1];
		i++;
	}
	stack->stackB[find_top_b(stack)] = save;
	stack->cmd = ft_strjoin(stack->cmd, "pb\n");
}

void	pa(t_stack *stack)
{
	int	save;
	int	i;

	save = stack->stackB[find_top_b(stack) + 1];
	if (save == 0)
		return ;
	stack->stackB[find_top_b(stack) + 1] = 0;
	i = stack->size;
	while (i > 0)
	{
		stack->stackA[i] = stack->stackA[i - 1];
		i--;
	}
	stack->stackA[i] = save;
	stack->cmd = ft_strjoin(stack->cmd, "pa\n");
}

int	find_botton(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->stackA[i])
		i++;
	while (stack->stackA[i] == 0)
		i--;
	return (i);
}
