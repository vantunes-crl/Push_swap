#include "push_swap.h"

void sa(t_stack *stack) //swap the top two numbers in a stack A
{
    int temp = stack->stackA[0];
    if (stack->stackA[1] == 0)
        return ;
    stack->stackA[0] = stack->stackA[1];
    stack->stackA[1] = temp;
    stack->cmd = ft_strjoin(stack->cmd, " sa");
}

void sb(t_stack *stack) //swap the top two numbers in a stack B
{
    int temp = stack->stackB[find_top_b(stack) + 1];
    stack->stackB[find_top_b(stack) + 1] = stack->stackB[find_top_b(stack) + 2];
    stack->stackB[find_top_b(stack) + 2] = temp;
    stack->cmd = ft_strjoin(stack->cmd, " sb");
}

void ss(t_stack *stack) //swap the top two numbers in a stack A and B
{
    sa(stack);
    sb(stack);
    stack->cmd = ft_strjoin(stack->cmd, " sa sb");
}

int find_botton(t_stack *stack)
{
    int i = 0;
    while (stack->stackA[i])
        i++;
    while (stack->stackA[i] == 0)
        i--;
    return (i);
}

void rra(t_stack *stack) //swap the botton to the top stack A
{
    int botton = find_botton(stack);
    int x = stack->stackA[botton], i;
    for (i = botton; i > 0; i--)
        stack->stackA[i] = stack->stackA[i-1];
    stack->stackA[0] = x;
    stack->cmd = ft_strjoin(stack->cmd, " rra");
}

void rrb(t_stack *stack) //swap the botton to the top stack B
{
    int x = stack->stackB[stack->size], i;
    for (i = stack->size; i > 0; i--)
        stack->stackB[i] = stack->stackB[i - 1];
    stack->stackB[find_top_b(stack)] = x;
    stack->cmd = ft_strjoin(stack->cmd, " rrb");
}

void rrr(t_stack *stack) // swap the top to the botton stack A and B
{
    rrb(stack);
    rra(stack);
    stack->cmd = ft_strjoin(stack->cmd, " rrb rra");
}

void ra(t_stack *stack) // swap the top to the botton stack A
{
    int botton = find_botton(stack);
    int x = stack->stackA[0], i;
    for (i = 0; i <= botton; i++)
        stack->stackA[i] = stack->stackA[i + 1];
    stack->stackA[botton] = x;
    stack->cmd = ft_strjoin(stack->cmd, " ra");
}

void rb(t_stack *stack) // swap the botton to the top stack B
{
    int top = stack->stackB[find_top_b(stack) + 1];
    int botton = stack->stackB[stack->size];
    int i = find_top_b(stack) + 1;
    while (i <= stack->size)
    {
        stack->stackB[i] = stack->stackB[i + 1];
        i++;
    }
    stack->stackB[stack->size] = top;
    stack->cmd = ft_strjoin(stack->cmd, " rb");
}

void rr(t_stack *stack) // swap the botton to the top stack A and B
{
    ra(stack);
    rb(stack);
    stack->cmd = ft_strjoin(stack->cmd, " ra rb");
}

int find_top_b(t_stack *stack)
{
    int i = 0;
    i = stack->size;
    while (stack->stackB[i] != 0)
        i--;
    return (i);
}

void pb(t_stack *stack)
{
    int save = 0;
    int i = 0;
    save = stack->stackA[0];
    if (save == 0)
        return ;
    i = 0;
    while (i <= stack->size)
    {
        stack->stackA[i] = stack->stackA[i + 1];
        i++;
    }
    stack->stackB[find_top_b(stack)] = save;
    stack->cmd = ft_strjoin(stack->cmd, " pb");
}

void pa(t_stack *stack)
{
    int save = stack->stackB[find_top_b(stack) + 1];
    if (save == 0)
        return ;
    stack->stackB[find_top_b(stack) + 1] = 0;
    int i = stack->size;
    while (i)
    {
        stack->stackA[i] = stack->stackA[i - 1];
        i--;
    }
    stack->stackA[i] = save;
    stack->cmd = ft_strjoin(stack->cmd, " pa");
}
