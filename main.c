#include "push_swap.h"

int main(int argc, char **argv)
{   
    t_stack stack;
    int i = 0;
    int j = 1;
    stack.cont_move = 0;
    stack.pos = 0;
    stack.cmd = "";
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
        int middle;
        while (find_new_size(&stack) > 3)
        {
            middle = midle_number(&stack);
            organize_a(&stack, middle);
        }
        organize_3(&stack);
        while (find_new_size_b(&stack) > 0)
            organize_b(&stack);
    }
    //else
      //  organize_500(&stack);
    write(1,stack.cmd, ft_strlen(stack.cmd));
    free(stack.cmd);
    free(stack.stackA);
    free(stack.stackB);
} 
