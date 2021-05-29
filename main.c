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

void veryfi_top_botton(t_stack *stack, int middle)
{
    if (stack->stackA[1] == find_small(stack) && stack->stackB[find_top_b(stack) + 2] == find_big_nb(stack))
        ss(stack);
    else if (stack->stackB[find_top_b(stack) + 2] == find_big_nb(stack) && find_new_size_b(stack) > 3)
        sb(stack);
    else if(stack->stackA[1] == find_small(stack))
        sa(stack);
    while(stack->stackA[0] < middle)
        pb(stack);
    int size = find_new_size(stack);
    has_less(stack,middle);
    if (stack->pos > size / 2)
    {
        while (has_less(stack, middle))
        {
            while (stack->stackA[0] < middle)
                pb(stack);
            rra(stack);
            while (stack->stackA[0] < middle)
                pb(stack);
        }
    }
    else
    {
        while (has_less(stack, middle))
        {
            while (stack->stackA[0] < middle)
                pb(stack);
            ra(stack);
            while (stack->stackA[0] < middle)
                pb(stack);
        }
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

int main(int argc, char **argv)
{   
    t_stack stack;
    int i = 0;
    int j = 1;
    stack.cont_move = 0;
    stack.pos = 0;
    stack.cmd = "";
    stack.size = argc - 1;
    stack.stackA = calloc(stack.size, sizeof(int *));
    stack.stackB = calloc(stack.size, sizeof(int *));
    i = -1;
    while (++i < stack.size)
    {
        stack.stackA[i] = atoi(argv[j]);
        j++;
    }
    if (argc == 4)
        organize_3(&stack);
    else if (argc <= 101)
    {
        int middle;
        while (find_new_size(&stack) > 3)
        {
            middle = midle_number(&stack);
            veryfi_top_botton(&stack, middle);
        }
        organize_3(&stack);
        while (find_new_size_b(&stack) > 0)
            organize_b(&stack);
    }
    write(1,stack.cmd, ft_strlen(stack.cmd));
    free(stack.cmd);
    free(stack.stackA);
    free(stack.stackB);
} 
