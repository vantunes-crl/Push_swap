#include "push_swap.h"

int find_big(t_stack *stack)
{
    int i = 0;
    int big;
    big = -9999;
    while (i <= stack->size)
    {
        if (big <= stack->stackB[i] && stack->stackB[i] != 0)
            big = stack->stackB[i];
        i++;
    }
    i = 0;
    while (i <= stack->size)
    {
        if (big == stack->stackB[i])
            return (i);
        i++;
    }
    return 0;
}

int find_small(t_stack *stack)
{
    int i = 0;
    int small;
    small = stack->stackA[i];
    while (i <= stack->size)
    {
        if (small > stack->stackA[i] && stack->stackA[i] != 0)
            small = stack->stackA[i];
        i++;
    }
    return (small);
}

int find_top_b(t_stack *stack)
{
    int i = 0;
    i = stack->size;
    while (stack->stackB[i] != 0)
        i--;
    return (i);
}

int find_new_size(t_stack *stack)
{
    int i = 0;
    int count = 0;
    while (i < stack->size)
    {
        if (stack->stackA[i] != 0)
            count++;
        i++;
    }
    return (count);
}

int find_new_size_b(t_stack *stack)
{
    int i = 0;
    int count = 0;
    while (i <= stack->size)
    {
        if (stack->stackB[i] != 0)
            count++;
        i++;
    }
    return (count);
}

int find_botton(t_stack *stack)
{
    int i = 0;
    while (stack->stackA[i])
        i++;
    while (stack->stackA[i] == 0)
        i--;
    return (i);
}