# push_swap_private


### Journey

#### Day 1 - Thursday

I managed to write a program that sort an array of three numbers. The numbers are hardcoded. They are  not take from the command line. The Algorithm looks for the smallest value in the stack A, it bring it to the top of the stack throug rotation (ra) and then push it to b. The process is repeated till the stack A is empty. I had to make an architectural decition regarding the 'form' of the stack. They could have been a linked list or an array. The disadvantage of an array of ints ist that there is no 'flag' like the null terminator for array of chars telling us when we are at the end of the string, so I had to create a variable 'size' which keep count of the size of the stack A and the stack B. I implemented 5 operations (pa, pb, sw, sb, ra) out of 11, but ended up using only 3: ra, pa, pb. What I understood at the beginning of the day 2, while reordering all the material I read, is that I did a naive implemetation of the Insertion Sort algorithm.

#### Day 2 - Friday

Goal: take arguments from the command line and populate the array with those values. 

#### Day 3 - Monday 20/02/23

Goal: Write a Makefile and 'clean' everything. 

Background: At the moment all functions has been just copied into push_swap.c, also functions from the libft library. Even if there is no file limitaions for push_swap it would be a good practice to be able to compile libft together with push_swap

# 19/03/23

I started again to work on push_swap yesterday after three weeks pause. What I will try now is instead of searching for the smallest number and push it from a to b, I will search for the smallest n numbers in a and push them to b. Whkjile push them to b I will sort them. This algorithm would be then a mix of insertion and selection sort. *Selection sort* is a sorting algorithm that look for the smallest (or biggest) element in an array and put it at the beginning (or the end) of the array. *Insertion sort* loops over the array to be sorted and compare the first number with the next one, if the next one is lower, the lower number is moved before that number, if the next one is bigger, the next bigger number becomes the new number to compared with the next one. If there are many lower numbers behind the 'focus' number the lower number is moved to its right place. 
