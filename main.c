#include "push_swap.h"

void organize_5(t_stack *stack)
{
    pb(stack);
    pb(stack);
    organize_3_a(stack);
    pa(stack);
    int topA = stack->stackA[0];
    int botton = stack->stackA[find_botton(stack)];
    topA = stack->stackA[0];
    botton = stack->stackA[find_botton(stack)];
    if (topA > botton)
        ra(stack);
    else if (stack->stackA[0] > stack->stackA[1])
        sa(stack);
    pa(stack);
    if (stack->stackA[0] > stack->stackA[1] && stack->stackA[0] > stack->stackA[2])
    {
        pb(stack);
        pb(stack);
        sb(stack);
        pa(stack);
        sa(stack);
        pa(stack);
    }
}

void organize_3_b(t_stack *stack)
{
    int botton = stack->stackB[stack->size] ;
    int top = stack->stackB[find_top_b(stack) + 1];
    int middle = stack->stackB[stack->size - 1];
    if (top > middle && middle < botton && botton > top) // 2 1 3
    {
        printf("\033[1;36mUsed \033[1;32msb\n");
        sb(stack);
    }
    else if (top > middle && middle > botton && botton < top) // 3 2 1
    {
        printf("\033[1;36mUsed \033[1;32msa rrb\n");
        sb(stack);
        rrb(stack);
    }
    else if (top > middle && middle < botton && botton < top) // 3 1 2
    {
        printf("\033[1;36mUsed \033[1;32m rb\n");
        rb(stack);
    }
    else if (top < middle && middle > botton && botton > top) // 1 3 2
    {
        printf("\033[1;36mUsed\033[1;32m sb rb\n");
        sb(stack);
        rb(stack);
    }
    else if (top < middle && middle > botton && botton < top) // 2 3 1
    {
        printf("\033[1;36mUsed\033[1;32m rrb\n");
        rrb(stack);
    }
}

void organize_3_a(t_stack *stack)
{
    int botton = stack->stackA[2] ;
    int top = stack->stackA[0];
    int middle = stack->stackA[1];
    if (top > middle && middle < botton && botton > top) // 2 1 3
    {
        printf("\033[1;36mUsed \033[1;32msa\n");
        sa(stack);
    }
    else if (top > middle && middle > botton && botton < top) // 3 2 1
    {
        printf("\033[1;36mUsed \033[1;32msa rra\n");
        sa(stack);
        rra(stack);
    }
    else if (top > middle && middle < botton && botton < top) // 3 1 2
    {
        printf("\033[1;36mUsed \033[1;32m ra\n");
        ra(stack);
    }
    else if (top < middle && middle > botton && botton > top) // 1 3 2
    {
        printf("\033[1;36mUsed\033[1;32m sa ra\n");
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > botton && botton < top) // 2 3 1
    {
        printf("\033[1;36mUsed\033[1;32m rra\n");
        rra(stack);
    }
}

int main(int argc, char **argv)
{   
    t_stack stack;
    int i;
    int j = 1;

    stack.size = argc - 2;
    stack.stackA = calloc(stack.size + 1, sizeof(int));
    stack.stackB = calloc(stack.size + 1, sizeof(int));
    i = 0;
    while (i <= stack.size)
    {
        stack.stackA[i] = atoi(strdup(argv[j]));
        j++;
        i++;
    }
    i = 0;
    if (argc == 4)
        organize_3_a(&stack);
    else if (argc == 6)
        organize_5(&stack);
    while (i <= stack.size)
    {
        if (stack.stackA[i] == 0)
            printf(" ");
        else
            printf("   \033[1;33m%-6d", stack.stackA[i]);
        if (stack.stackB[i] == 0)
            printf(" ");
        else
            printf("\033[1;31m%10d", stack.stackB[i]);
        i++;
        printf("\n");
    }
    printf("\033[1;33m stackA");
    printf("\033[1;31m stackB");
    printf("\n");
}