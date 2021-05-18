#include "push_swap.h"

void organize_3(t_stack *stack)
{
    int botton = stack->stackA[2] ;
    int top = stack->stackA[0];
    int middle = stack->stackA[1];
    if (top > middle && middle < botton && botton > top) // 2 1 3
    {
        printf("\033[1;36mUsed \033[1;32msa\n\n");
        sa(stack);
    }
    else if (top > middle && middle > botton && botton < top) // 3 2 1
    {
        printf("\033[1;36mUsed \033[1;32msa rra\n\n");
        sa(stack);
        rra(stack);
    }
    else if (top > middle && middle < botton && botton < top) // 3 1 2
    {
        printf("\033[1;36mUsed \033[1;32m ra\n\n");
        ra(stack);
    }
    else if (top < middle && middle > botton && botton > top) // 1 3 2
    {
        printf("\033[1;36mUsed\033[1;32m sa ra\n\n");
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > botton && botton < top) // 2 3 1
    {
        printf("\033[1;36mUsed\033[1;32m rra\n\n");
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
    organize_3(&stack);
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