#include "push_swap.h"

void ft_sort(int size, int *array)
{
    int i = 0;
    while (i < size)
    {
        if (array[i] > array[i + 1])
        {
            int temp;
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
    i++;
    }
}

int middle_move(t_stack *stack)
{
    int *array;
    int middle;
    array = ft_calloc(stack->size, sizeof(int *));
    ft_memcpy(array , stack->stackA, sizeof(int *) * stack->size);
    ft_sort(stack->size, array);
    stack->chunk = stack->chunk + (stack->size / 10);
    middle = array[stack->chunk];
    free(array);
    return (middle);
}