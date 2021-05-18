#include "push_swap.h"

int main()
{   
    t_stack stack;
    int i;

    stack.size = 5;
    stack.stackA = calloc(stack.size + 1, sizeof(int));
    stack.stackB = calloc(stack.size + 1, sizeof(int));
    i = -1;
    while (i <= stack.size)
    {
        stack.stackA[i] = i + 1;
        i++;
    }
    i = 0;
    pb(&stack);
    pb(&stack);
    pb(&stack);
    rb(&stack);
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