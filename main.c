#include "push_swap.h"

int main()
{   
    t_stack stack;
    int i;
    stack.sizeA = 6;
    stack.sizeB = 6;
    stack.init_size = 4;
    stack.stackA = calloc(stack.sizeA, sizeof(int));
    stack.stackB = calloc(stack.sizeB, sizeof(int));
    i = -1;
    while (++i < 5)
        stack.stackA[i] = i + 1;
    i = 0;
    while (i < stack.sizeA - 1 || i < stack.sizeB - 1)
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