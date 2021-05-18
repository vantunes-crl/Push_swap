#include "push_swap.h"

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
        if (!argv[j])
            break;
        stack.stackA[i] = atoi(strdup(argv[j]));
        j++;
        i++;
    }
    i = 0;
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