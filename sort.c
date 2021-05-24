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