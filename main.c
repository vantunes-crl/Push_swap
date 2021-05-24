#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i = 0;
    printf("\033[1;36mUsed\033[1;34m%s\n", stack->cmd);
    printf("\033[1;36mSize\033[1;34m %d\n", stack->size + 1);
    while (i <= stack->size)
    {
        if (stack->stackA[i] == 0)
            printf(" ");
        else
            printf("   \033[1;33m%-6d", stack->stackA[i]);
        if (stack->stackB[i] == 0)
            printf(" ");
        else
            printf("\033[1;31m%10d", stack->stackB[i]);
        i++;
        printf("\n");
    }
    printf("\033[1;33m stackA");
    printf("\033[1;31m stackB");
    printf("\n");

}

int ft_strlen(const char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return(i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	news = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i] != '\0')
	{
		news[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		news[i] = s2[j];
		j++;
		i++;
	}
	news[i] = '\0';
	return (news);
}

int find_big(t_stack *stack)
{
    int i = 0;
    int big;
    big = stack->stackA[i];
    while (i <= stack->size)
    {
        if (big < stack->stackA[i])
            big = stack->stackA[i];
        i++;
    }
    i = 0;
    while (i <= stack->size)
    {
        if (big == stack->stackA[i])
            return (i);
        i++;
    }
    return (-1);
}

int find_small(t_stack *stack)
{
    int i = 0;
    int small;
    small = stack->stackA[i];
    while (i <= stack->size)
    {
        if (small > stack->stackA[i] && stack->stackA[i] != 0)
            small = stack->stackA[i];
        i++;
    }
    return (small);
}

int find_position(t_stack *stack, int number)
{
    int i = 0;
    while (i < stack->size)
    {
        if (stack->stackA[i] == number)
            break;
        i++;
    }
    return (i);
}

void move_top(t_stack *stack)
{
    int small = find_small(stack);
    int pos = find_position(stack, small);
    int j = 0;
    if (pos > (stack->size / 2))
    {
        while (j < stack->size)
        {
            if (stack->stackA[0] == small)
                break;
            rra(stack);
            j++;
        }
    }
    else
    {
        while (j < stack->size)
        {
            if (stack->stackA[0] == small)
                break;
            ra(stack);
            j++;
        }
    }
}

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

int find_new_size(t_stack *stack)
{
    int i = 0;
    int count = 0;
    while (i < stack->size)
    {
        if (stack->stackA[i] != 0)
            count++;
        i++;
    }
    return (count);
}

int main(int argc, char **argv)
{   
    t_stack stack;
    int i;
    int j = 1;

    stack.cmd = " ";
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
    if (argc == 4)
        organize_3(&stack);
    else
    {
        int *array;
        array = malloc(sizeof(int) * stack.size + 1);
        memcpy(array , stack.stackA, sizeof(int) * stack.size + 1);
        ft_sort(stack.size, array);
        int middle = (stack.size) / 2;
        middle = array[middle + 1];
        i = -1;
        while (++i <= stack.size)
        {
           if (stack.stackA[0] < middle)
            {
                while (stack.stackA[0] < middle)
                    pb(&stack);
            }
            else
                break ;
        }
        i = 0;
        while (i <= stack.size)
        {
            ra(&stack);
            while (stack.stackA[0] < middle)
                pb(&stack);
            i++;
        }
        free(array);
        int size = find_new_size(&stack);
        array = malloc(sizeof(int) * size);
        i = 0;
        while (i <= size)
        {
            array[i] = stack.stackA[i];
            i++;
        }
        middle = size / 2;
        middle = array[middle];
        i = -1;
        while (++i <= size)
        {
            if (stack.stackA[0] < middle)
            {
                while (stack.stackA[0] < middle)
                    pb(&stack);
            }
            else
                break ;
        }
        i = -1;
        while (++i <= size)
        {
            rra(&stack);
            while (stack.stackA[0] < middle)
                pb(&stack);
        }
        print_stack(&stack);
    }
}
