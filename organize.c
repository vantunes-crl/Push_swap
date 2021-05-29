#include "push_swap.h"

void organize_3(t_stack *stack)
{
    int botton = stack->stackA[2] ;
    int top = stack->stackA[0];
    int middle = stack->stackA[1];
    if (top > middle && middle < botton && botton > top) // 2 1 3
        sa(stack);
    else if (top > middle && middle > botton && botton < top) // 3 2 1
    {
        sa(stack);
        rra(stack);
    }
    else if (top > middle && middle < botton && botton < top) // 3 1 2
        ra(stack);
    else if (top < middle && middle > botton && botton > top) // 1 3 2
    {
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > botton && botton < top) // 2 3 1
        rra(stack);
}

void organize_a(t_stack *stack, int middle)
{
    while(stack->stackA[0] < middle)
        pb(stack);
    int size = find_new_size(stack);
    has_less(stack,middle);
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

void organize_b(t_stack *stack)
{
    if (stack->stackB[find_top_b(stack) + 2] == find_big_nb(stack) && find_new_size_b(stack) > 3)
        sb(stack);
    int new_size = find_new_size_b(stack);
    new_size = new_size / 2;
    int distance = (find_big(stack) - find_top_b(stack));
    while (stack->stackB[find_top_b(stack) + 1] != stack->stackB[find_big(stack)])
    {
        if (distance > new_size)
            rrb(stack);
        else
            rb(stack);
    }
    pa(stack);
}
