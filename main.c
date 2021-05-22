#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i = 0;
    printf("\033[1;36mUsed\033[1;34m%s\n", stack->cmd);
    printf("\033[1;36mSize\033[1;34m %d\n", stack->size);
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

int main(int argc, char **argv)
{   
    t_stack stack;
    int i;
    int j = 1;

    stack.cmd = " ";
    stack.size = argc - 2;
    stack.stackA = calloc(stack.size, sizeof(int *));
    stack.stackB = calloc(stack.size, sizeof(int *));
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
        i = 0;
        while (i < stack.size)
        {
            move_top(&stack);
            pb(&stack);
            i++;
        }
        i = 0;
        while (i++ < stack.size)
        {
            pa(&stack);
        }
        print_stack(&stack);
    }
}
