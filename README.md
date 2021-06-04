# Push swap
  
## The goal of this project is to organize a stack of numbers with limited commands and an auxiliary stack.

### commands:
 - sa : swap a - swap the first 2 elements at the top of stack a. Do   
   nothing if there is only one or no elements).
 - sb : swap b - swap the first 2 elements at the top of stack b. Do
   nothing if there is only one or no elements).
 - ss : sa and sb at the same time.     
 - pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 - pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. 
 - ra : rotate a - shift up all elements of stack a by 1. The first element becomes   the last one.
 - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
 - rr : ra and rb at the same time.
 - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
 - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
 - rrr : rra and rrb at the same time.

## The technique I used for this project was based on [Push_swap: the least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### But it doesn't explain exactly what chunks are and what to do exactly , but it's a great start.

# Steps:

 1. Put all the numbers you get put into an array and sort them.
 2. Divide the number of arguments by 2.
 3. Get the value of the division , and use it to find the middle number in the array.
 4. Send everything less then this number to stack B.
 5. Do this , over and over until stackA is empty or with 3 elements.
 6. Then just look for the highest number in stackB and send it to stackA until stackB is empty.
 
 note: when sending to stackA for stackB or the inverse , always check if it is better to use rra or ra , rb or rrb , to pull the number to the top
 
 ## Bonus

bonus is for making a checker , which reads the commands and checks if those commands really organize the stack.

    ./push_swap 5 3 4 6 7 | ./checker 5 3 4 6 7
	output: OK
	or
	output: KO

## install Push_swap and checker

    make all
