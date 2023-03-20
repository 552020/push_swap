# push_swap

"Because Swap_push isn't as natural"

## Summary

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible numbers of actions. To suceed you'll have to manipulate various type of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting. 

## Chapter I - Foreward
-
## Chapter II - Introduction

The goal of the project is to sort a set of integer values. We need not just to sort them, but we need to sort them with the least amount of steps, given the following limitations: we have only a certain amount of operations to our disposal, and we can use only two 'stacks' to sort the values. A stack 'A' which is supposed to hold the values we need to sort, in the order we initially get it, and an empty stack 'B' that we can use to sort them. One of the permitted operations allows us to move (pop) an element from the top of one of the two stack and put (push) it on the top of the other one. 
We need to write a program, that perform this sorting operation and give as an output not the sorted stack, but the exact sequence of operations we performed to sort the values in the queue. 

### TODO

- Remove this paragraph, which is just a repetition

We have at our disposal two "stack" or data collection structures. The first one is supposed to hold the integer values that we need to sort. We will get the integer values as arguments of our program, and we are supposed to fill the first stack with the given integers values. The second 'stack' is an empty stack, that we can use to sort the values hold in the first stack. 
- Explain in details why the data structure we have to our disposal is not a 'pure' stack.

## Chapter III - Objectives

> Writing a sorting algorithm is always a very important step in a developer's journey. It is often the first encounter with the concept of complexity. 

## Chapter IV - Common Instructions

- It's a C program. 
- It follows the 42's Norm. 

### Makefile

- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

- I wrote a lot of commentaries in the Makefile itself. Move the commentaries from the Makefile to her. 

[X] Write a Makefile
[]	Write a Makefile that import libft.

#### `:=` instead of `=` 

- `:=` the value of the variable is fixed and can't be changed during the executioin of make. Is a good practice to use `:=` instead `=` for variables which values don't change during the execution

#### make -C libft

The make -C command is used to execute make in a subdirectory 

## Glossary

### Is the data structure we are given a stack? 

Actually not, cause a stack is an abstract data type, which is well exemplfied by a pile of plates. You can add a plate to the pile adding it to the top of the pile and remove it from the top of pile as well. In a normale stack we have only these two kind of operations, push (adding an element) and pop (removing the element). In push_swap the *pa* operation (push a) is at the same time a pop operation on the stack A and a push operation on the stack B. Swap, rotate and reverse rotate are not operation normally allowed in a normal stack.  
- Stack 
A stack is an abstract data type, that represents a collection of elements
- Heap
- Queue

### What is 'Complexity'?

Complexity is mentioned in Chapter III. Discuss which kind of complexity we deal in this algorithm. I think it's not the 'normal' complexity we have to deal with.

We have two kind of complexity: time complexity and space complexity. Time complexity is measured on the number of operations needed to perform the algorithm and space complexity refers to the memory needed to perform the algorithm. 

