# push_swap

## Overview

[Push_Swap](./en.subject.pdf) is a project of the [School 42](https://www.42berlin.de/) about sorting numbers on a 'stack' A, with the help of auxiliary stack B and using a restricted set of instructions, which are:

- _sa_: Swap the top two elements of stack A. (Swap A)
- _sb_: Swap the top two elements of stack B. (Swap B)
- _ss_: Swap the top two elements of both stack A and stack B simultaneously. (Swap both)
- _pa_: Pop the top element from stack B and push it onto the top of stack A. (Push A)
- _pb_: Pop the top element from stack A and push it onto stack B. (Push B)
- _ra_: Rotate all elements of stack A upward by one. The top element becomes the bottom element. (Rotate A)
- _rb_: Rotate all elements of stack B upward by one. The top element becomes the bottom element. (Rotate B)
- _rr_: Rotate all elements of both stack A and stack B upward by one. (Rotate both)
- _rra_: Rotate all elements of stack A downward by one. The bottom element becomes the top element. (Reverse rotate A)
- _rrb_: Rotate all elements of stack B downward by one. The bottom element becomes the top element. (Reverse rotate B)
- _rrr_: Rotate all elements of both stack A and stack B downward by one. (Reverse rotate both)

As you can see from the permitted operations the 'stack' is not a 'real' stack, but this is the way this data strcture is referenced in the instructions.

We need not just to sort them, but we need to sort within a certain amount of steps, which will determine the evaluation:

3 numbers -> 2 or 3 moves
5 numbers -> <12 moves
100 numbers:
<700 moves = 5 pts
<900 moves = 4 pts
<1,100 moves = 3 pts
<1,300 moves = 2 pts
<1,500 moves = 1 pts
500 numbers:
<5,500 moves = 5 pts
<7,000 moves = 4 pts

A move is not an operation like in the normal time complexity meaning but it a 'printed operation'.
At this point it's important to note that it's not the actual number of operations that count, but the operations printed by the program to sort the 'stack'. The actual goal of the program is not to sort the integers in the first 'stack', but to print the operations necessary to sort them. The elements of the array in memory could remain unsorted, and actually we could even don't build an array or any data structure holding the values we get as an input.

## My approach

My approach to solving the Push_Swap project involved initially attempting a naive approach similar to a selection sort. This approach involved finding the smallest integer in stack A, bringing it to the top of the stack, and then pushing it to stack B. However, I quickly realized that this approach was not efficient enough to handle larger sets of integers.

## TODO

- [x] main algorithm
- [x] algorighm for small sets
- [x] norminette
- [ ] check all headers before submitting
- [ ] eventually integrate ft_printf in libft
- [ ] improve the README

## Notes

### `:=` instead of `=`

- `:=` the value of the variable is fixed and can't be changed during the executioin of make. Is a good practice to use `:=` instead `=` for variables which values don't change during the execution

#### make -C libft

The make -C command is used to execute make in a subdirectory

### Is the data structure we are given a stack?

Actually not, cause a stack is an abstract data type, which is well exemplfied by a pile of plates. You can add a plate to the pile adding it to the top of the pile and remove it from the top of pile as well. In a normale stack we have only these two kind of operations, push (adding an element) and pop (removing the element). In push*swap the \_pa* operation (push a) is at the same time a pop operation on the stack A and a push operation on the stack B. Swap, rotate and reverse rotate are not operation normally allowed in a normal stack.

- Stack
  A stack is an abstract data type, that represents a collection of elements
- Heap
- Queue

### What is 'Complexity'?

Complexity is mentioned in Chapter III. Discuss which kind of complexity we deal in this algorithm. I think it's not the 'normal' complexity we have to deal with.

We have two kind of complexity: time complexity and space complexity. Time complexity is measured on the number of operations needed to perform the algorithm and space complexity refers to the memory needed to perform the algorithm.

## Disclaimer about the Coding Style

**Disclaimer:** This code has been written the "[The Norm](./en.norm.pdf)" of 42, which is a set of strict coding style rules. It aims to ensure consistency and readability of the codebase.

The following are some of the principal rules enforced by the Norm:

1. **Indentation**: Code should be indented using four spaces for each level of indentation to enhance clarity and maintain a consistent visual structure.

2. **Function Length**: Functions should be kept concise, containing no more than twenty-five lines of code. This practice helps to manage complexity and improves code readability.

3. **Naming Conventions**: Variables, functions, and files should be named with precision and brevity, following the recommended naming conventions. This promotes code understandability and consistency.

4. **Headers**: Each source file should include a header at the beginning, providing essential information such as the author's name, the project's name, and a brief description of its purpose.

5. **Forbidden Acts**: The Norm restricts the use of certain language features, such as `for` or `goto` statements, to ensure code quality and discourage potential pitfalls.

While adhering to the Norm may initially present challenges, it fosters discipline and order in coding practices, resulting in clean and well-structured code. Embrace the Norm, and let it guide you towards creating code that is both functional and aesthetically pleasing.

_Note: The Norm of 42 is specific to the 42 coding school, but its principles and best practices can be valuable in professional software development environments as well._
