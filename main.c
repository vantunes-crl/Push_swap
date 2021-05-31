#include "push_swap.h"

int main(int argc, char **argv)
{   
    t_stack stack;
    int i = 0;
    int j = 1;
    stack.cont_move = 0;
    stack.pos = 0;
    stack.cmd = "";
    stack.chunk = 0;
    stack.size = argc - 1;
    stack.stackA = calloc(stack.size, sizeof(int *));
    stack.stackB = calloc(stack.size, sizeof(int *));
    i = -1;
    while (++i < stack.size)
    {
        stack.stackA[i] = atoi(argv[j]);
        j++;
    }
    // if (if_order(&stack))
    // {
    //     write(1,"ordened\n",7);
    //     exit(0);
    // }
    // if (check_doble(&stack))
    // {
    //     write(1,"double\n", 7);
    //     exit(0);
    // }
    if (argc == 4)
        organize_3(&stack);
    else
    {
        int middle;
        while (find_new_size(&stack) > 3)
        {
            if (argc - 1 <= 101)
                middle = midle_number(&stack);
            else
                middle = middle_move(&stack);
            organize_a(&stack, middle);
        }
        organize_3(&stack);
        while (find_new_size_b(&stack) > 0)
            organize_b(&stack);
    }
    // if (if_order(&stack))
    // {
    //    printf("ordened\n");
    //    exit(0);
    // }
    // i = 0;
    // while (i < stack.size)
    //    printf("%d ",stack.stackA[i++]);
    
    write(1,stack.cmd, ft_strlen(stack.cmd));
    free(stack.cmd);
    free(stack.stackA);
    free(stack.stackB);
} 
