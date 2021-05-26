#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i = 0;
    printf("\033[1;36mUsed\033[1;34m%s\n", stack->cmd);
    printf("\033[1;36mSize\033[1;34m %d\n", stack->size);
    printf("\033[1;36mmoves\033[1;34m %d\n", stack->cont_move);
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
    big = stack->stackB[0];
    while (i <= stack->size)
    {
        if (big <= stack->stackB[i])
            big = stack->stackB[i];
        i++;
    }
    i = 0;
    while (i <= stack->size)
    {
        if (big == stack->stackB[i])
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

int find_new_size_b(t_stack *stack)
{
    int i = 0;
    int count = 0;
    while (i <= stack->size)
    {
        if (stack->stackB[i] != 0)
            count++;
        i++;
    }
    return (count);
}

int midle_number(t_stack *stack)
{
    int *array;
    array = malloc(sizeof(int *) * find_new_size(stack));
    memcpy(array , stack->stackA, sizeof(int *) * find_new_size(stack));
    ft_sort(find_new_size(stack), array);
    int middle = find_new_size(stack) / 2;
    middle = array[middle];
    free(array);
    return (middle);
}

int has_less(t_stack *stack, int middle)
{
    int i = 0;
    while (i < stack->size)
    {
        if (stack->stackA[i] < middle && stack->stackA[i] != 0)
        {
            stack->pos = i;
            return (1);
        }
        i++;
    }
    return (0);
}

void veryfi_top_botton(t_stack *stack, int middle)
{
    while(stack->stackA[0] < middle)
        pb(stack);
    int size = find_new_size(stack);
    has_less(stack,middle);
    if (stack->pos > size / 2)
    {
        while (has_less(stack, middle))
        {
            while (stack->stackA[0] < middle)
                pb(stack);
            rra(stack);
        }
    }
    else
    {
        while (has_less(stack, middle))
        {
            while (stack->stackA[0] < middle)
                pb(stack);
            ra(stack);
        }
    }
}

void organize_b(t_stack *stack)
{
    int new_size = find_new_size_b(stack);
    new_size = new_size / 2;
    int distance = (find_big(stack) - find_top_b(stack));
    while (stack->stackB[find_top_b(stack) + 1] != stack->stackB[find_big(stack)])
    {
        if (distance > new_size)
            rrb(stack);
        else
            rb(stack);
    }
    pa(stack);
    new_size = find_new_size_b(stack);
    new_size = new_size / 2;
    distance = (find_big(stack) - find_top_b(stack));
    while (stack->stackB[find_top_b(stack) + 1] != stack->stackB[find_big(stack)])
    {
        if (distance > new_size)
            rrb(stack);
        else
            rb(stack);
    }
    pa(stack);
}

int main(int argc, char **argv)
{   
    t_stack stack;
    int i = 0;
    int j = 1;
    stack.cont_move = 0;
    stack.pos = 0;
    stack.cmd = " ";
    stack.size = argc - 1;
    stack.stackA = calloc(stack.size, sizeof(int *));
    stack.stackB = calloc(stack.size, sizeof(int *));
    i = -1;
    while (++i < stack.size)
    {
        stack.stackA[i] = atoi(argv[j]);
        j++;
    }
    if (argc == 4)
        organize_3(&stack);
    else
    {
        while (find_new_size(&stack) > 3)
        {
            int middle = midle_number(&stack);
            veryfi_top_botton(&stack, middle);
        }
        while (find_new_size_b(&stack) > 0)
            organize_b(&stack);
        pa(&stack);
        pa(&stack);
        printf("\033[1;36mmoves\033[1;34m %d\n", stack.cont_move);
       // print_stack(&stack);
    }
    
}
