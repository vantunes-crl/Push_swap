#include "push_swap.h"

int ft_strlen(const char *str)
{
    int i;
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
    i = 0;
    while (i <= stack->size)
    {
        if (small == stack->stackA[i])
            return (i);
        i++;
    }
    return (-1);
}

void move_top(t_stack *stack)
{
    int i = find_small(stack);
    while (i > 0)
    {
        ra(stack);
        i--;
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
        move_top(&stack);
        i = 0;
        while (i < stack.size)
        {
            move_top(&stack);
            pb(&stack);
            i++;
        }
        i = 0;
        while (i++ < stack.size)
            pa(&stack);
    }
    i = 0;
    printf("\033[1;36mUsed\033[1;34m%s\n\n", stack.cmd);
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