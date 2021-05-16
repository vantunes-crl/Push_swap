#include "push_swap.h"


int ft_itoa(char *str, int num)
{
    int i;

    i = -1;
    while (str[++i])
        num = num * 10 + (str[i] - 48);
    return (num);
}

int main(int argc , char **argv)
{
    int args = argc - 1;
    int i;
    int *stackA;
    int *stackB;
    int j = 0;

    i = 1;
    stackA = malloc(sizeof(int) * args);
    stackB = malloc(sizeof(int) * args);
    while (args)
    {
        stackA[j] = ft_itoa(argv[i], 0);
        i++;
        j++;    
        args--;
    }
    i = 0;
    while (stackA[i])
    {   
        printf("%d ", stackA[i]);
        i++;
    }
    i = 0;
    printf("\n");
    rra(stackA);
    while (stackA[i])
    {   
        printf("%d ", stackA[i]);
        i++;
    }
}