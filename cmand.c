#include "push_swap.h"

int sizeof_array(int *array)
{
    int i;
    i = 0;
    while (array[i])
        i++;
    return (i);
}

void sa(int *stackA) //swap the top two numbers in a stack A
{
    int temp = stackA[0];
    stackA[0] = stackA[1];
    stackA[1] = temp;
}

void sb(int *stackB) //swap the top two numbers in a stack A
{
    int temp = stackB[0];
    stackB[0] = stackB[1];
    stackB[1] = temp;
}

void ss(int *stackA, int *stackB) //swap the top two numbers in a stack A and B
{
    sa(stackA);
    sb(stackB);
}

void ra(int *stackA) //swap the top to the botton stack A
{
    int n = sizeof(stackA);
    int x = stackA[0], i;
    i = 0;
    while (i < n)
    {
        stackA[i] = stackA[i+1];
        i++;
    }
    stackA[n] = x;
}

void rb(int *stackB) //swap the top to the botton stack B
{
    int n = sizeof(stackB);
    int x = stackB[0], i;
    i = 0;
    while (i < n)
    {
        stackB[i] = stackB[i+1];
        i++;
    }
    stackB[n] = x;
}

void rr(int *stackA, int *stackB) // swap the top to the botton stack A and B
{
    rb(stackB);
    ra(stackA);
}

void rra(int *stackA) // swap the botton to the top stack A
{
    int n = sizeof(stackA);
    int x = stackA[n], i;
    for (i = n; i > 0; i--)
        stackA[i] = stackA[i-1];
    stackA[0] = x;
}

void rrb(int *stackB) // swap the botton to the top stack B
{
    int n = sizeof(stackB);
    int x = stackB[n], i;
    for (i = n; i > 0; i--)
        stackB[i] = stackB[i-1];
    stackB[0] = x;
}

void rrr(int *stackA, int *stackB) // swap the botton to the top stack A and B
{
    rra(stackA);
    rrb(stackB);
}
typedef struct s_stack
{
    int *stackA;
    int *stackB;
} t_stack;

void remove_top_b(t_stack *stack, int stackBsize) // send the top of B to the top of A
{
    int *new_stackB;
    int save;
    save = stack->stackB[0];
    int i = 0;
    new_stackB = malloc(sizeof(int) * stackBsize - 1);
    while (++i < stackBsize)
        new_stackB[i - 1] = stack->stackB[i];
    free(stack->stackB);
    stack->stackB = new_stackB;
}

int main()
{   
    t_stack stack;
    
    int i = -1;
    int stackAsize = 4;
    int stackBsize = 4;
    stack.stackA = malloc(sizeof(int) * stackAsize);
    stack.stackB = malloc(sizeof(int) * stackBsize);
    while (++i < 4)
        stack.stackB[i] = i + 1;
    remove_top_b(&stack, stackBsize);
    i = 0;
    while (stack.stackB[i])
    {
        printf("%d\n", stack.stackB[i]);
        i++;
    }
}