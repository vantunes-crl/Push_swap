#include "push_swap.h"

void	organize_3(t_stack *stack)
{
	int	botton;
	int	middle;
	int	top;

	botton = stack->stackA[2];
	top = stack->stackA[0];
	middle = stack->stackA[1];
	if (top > middle && middle < botton && botton > top)
		sa(stack);
	else if (top > middle && middle > botton && botton < top)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < botton && botton < top)
		ra(stack);
	else if (top < middle && middle > botton && botton > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > botton && botton < top)
		rra(stack);
}

void	organize_a(t_stack *stack, int middle)
{
	int	size;

	while (stack->stackA[0] < middle)
		pb(stack);
	size = find_new_size(stack);
	has_less(stack, middle);
	while (has_less(stack, middle))
	{
		while (stack->stackA[0] < middle)
			pb(stack);
		if (stack->pos > size / 2)
			rra(stack);
		else
			ra(stack);
		while (stack->stackA[0] < middle)
			pb(stack);
	}
}

void	organize_b(t_stack *stack)
{
	int	new_size;
	int	distance;

	if (stack->stackB[find_top_b(stack) + 2] == stack->stackB[find_big(stack)]
		&& find_new_size_b(stack) > 3)
		sb(stack);
	new_size = find_new_size_b(stack);
	new_size = new_size / 2;
	distance = (find_big(stack) - find_top_b(stack));
	while (stack->stackB[find_top_b(stack) + 1]
		!= stack->stackB[find_big(stack)])
	{
		if (distance > new_size)
			rrb(stack);
		else
			rb(stack);
	}
	pa(stack);
}
