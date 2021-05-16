#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


/* comand functions */

void sa(int *stackA); //swap the top two numbers in a stack A
void sb(int *stackB); //swap the top two numbers in a stack A
void ss(int *stackA, int *stackB); //swap the top two numbers in a stack A and B
void ra(int *stackA); //swap the top to the botton stack A
void rb(int *stackB); //swap the top to the botton stack B
void rr(int *stackA, int *stackB); // swap the top to the botton stack A and B
void rra(int *stackA); // swap the botton to the top stack A
void rrb(int *stackB); // swap the botton to the top stack B
void rrr(int *stackA, int *stackB); // swap the botton to the top stack A and B
int sizeof_array(int *array);
#endif