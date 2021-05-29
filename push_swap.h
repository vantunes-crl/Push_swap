#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct s_stack
{
    int *stackA;
    int *stackB;
    int size;
    int cont_move;
    int pos;
    int chunk;
    char *cmd;
} t_stack;

/* comand functions */

void    sa(t_stack *stackA); //swap the top two numbers in a stack A
void    sb(t_stack *stackB); //swap the top two numbers in a stack A
void    ss(t_stack *stackA); //swap the top two numbers in a stack A and B
void    ra(t_stack *stackA); //swap the top to the botton stack A
void    rb(t_stack *stackB); //swap the top to the botton stack B
void    rr(t_stack *stackA); // swap the top to the botton stack A and B
void    rra(t_stack *stackA); // swap the botton to the top stack A
void    rrb(t_stack *stackB); // swap the botton to the top stack B
void    rrr(t_stack *stackA); // swap the botton to the top stack A and B
void    pb(t_stack *stack); // send the top of B to A
void    pa(t_stack *stack); // send the top of A to B

/* organize functions */

void    organize_3(t_stack *stack);
void    organize_b(t_stack *stack);
void    organize_a(t_stack *stack, int middle);

/* find functions */
int     find_botton(t_stack *stack);
int     find_top_b(t_stack *stack);
int     find_big(t_stack *stack);
int     find_big_nb(t_stack *stack);
int     find_small(t_stack *stack);
int     find_new_size(t_stack *stack);
int     find_new_size_b(t_stack *stack);

/* utils */

int     has_less(t_stack *stack, int middle);
int     midle_number(t_stack *stack);
int     middle_move(t_stack *stack);
char    *ft_strjoin(char const *s1, char const *s2);
void    ft_sort(int size, int *array);
int     ft_strlen(const char *str);

#endif