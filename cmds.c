#include "push_swap.h"

void sa(t_stack *stack) //swap the top two numbers in a stack A
{
    int temp = stack->stackA[0];
    stack->stackA[0] = stack->stackA[1];
    stack->stackA[1] = temp;
}

void sb(t_stack *stack) //swap the top two numbers in a stack B
{
    int temp = stack->stackB[0];
    stack->stackB[0] = stack->stackB[1];
    stack->stackB[1] = temp;
}

void ss(t_stack *stack) //swap the top two numbers in a stack A and B
{
    sa(stack);
    sb(stack);
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
}

void rrb(t_stack *stack) //swap the botton to the top stack B
{
    int x = stack->stackB[4], i;
    for (i = 4; i > 0; i--)
        stack->stackB[i] = stack->stackB[i-1];
    stack->stackB[stack->init_size + 1] = x;
}

void rrr(t_stack *stack) // swap the top to the botton stack A and B
{
    rrb(stack);
    rra(stack);
}

void ra(t_stack *stack) // swap the top to the botton stack A
{
    int botton = find_botton(stack);
    int x = stack->stackA[0], i;
    for (i = 0; i <= botton; i++)
        stack->stackA[i] = stack->stackA[i + 1];
    stack->stackA[botton] = x;
}

void rb(t_stack *stack) // swap the botton to the top stack B
{
   int botton = stack->init_size + 1;
    int x = stack->stackB[4], i;
    for (i = 4; i >= 0; i--)
        stack->stackB[i] = stack->stackB[i - 1];
    stack->stackB[botton] = x;
}

void rr(t_stack *stack) // swap the botton to the top stack A and B
{
    ra(stack);
    rb(stack);
}

void pb(t_stack *stack)
{
    int save = 0;
    int i = 0;
    save = stack->stackA[0];
    if (save == 0)
        return ;
    i = 0;
    while (i < stack->sizeA - 1)
    {
        stack->stackA[i] = stack->stackA[i + 1];
        i++;
    }
    stack->stackB[stack->init_size--] = save;
}

void pa(t_stack *stack)
{
    int save = stack->stackB[stack->init_size + 1];
    if (save == 0)
        return ;
    stack->stackB[stack->init_size + 1] = 0;
    int i = stack->sizeA;
    while (i)
    {
        stack->stackA[i] = stack->stackA[i - 1];
        i--;
    }
    stack->stackA[i] = save;
}
