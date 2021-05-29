#include "push_swap.h"

int lenofnum(int n)
{
    int count = 1;
    while (n >= 10)
    {
        n = n / 10;
        count++;
    }
    return (count);
}

int has_biglen(t_stack *stack , int len)
{
    int i = 0;
    while (i < stack->size)
    {
        if (lenofnum(stack->stackA[i]) == len && stack->stackA[i] != 0)
        {
            stack->pos = i;
            return (1);
        }
        i++;
    }
    return (0);
}

void organize_500(t_stack *stack)
{
    int i = 0;
    int *array;

    array = malloc(sizeof(int *) * stack->size);
    memcpy(array , stack->stackA, sizeof(int *) * stack->size);
    ft_sort(find_new_size(stack), array);
    int biglen = lenofnum(array[stack->size]);
    int size = find_new_size(stack);
    i = 1;
    while (i <= biglen)
    {
        while (has_biglen(stack,i))
        { 
            if (stack->pos > size / 2)
                rra(stack);
            else
                ra(stack);
            if (lenofnum(stack->stackA[0]) == i)
                pb(stack);
        }
        i++;
    }
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
    organize_500(&stack);
    // i = 0;
    // while (i < stack.size)
    //    printf("%d\n", stack.stackA[i++]);
    // printf("\n");
    // i = 0;
    // while (i <= stack.size)
    //    printf("%d\n", stack.stackB[i++]);
    write(1,stack.cmd, ft_strlen(stack.cmd));
}