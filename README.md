# push_swap

## Overview

[Push_Swap](link-to-the-pdf) is a project of the [School 42](https://www.42.fr/) about sorting numbers on a 'stack' (which actually [is not a pure stack](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>)) using a restricted set of instructions.

The aim of the project is to sort a set of integer values. We need not just to sort them, but we need to sort them with the least amount of steps, given the following limitations: we have only a certain amount of operations to our disposal, and we can use only two 'stacks' to sort the values. A stack 'A' which is supposed to hold the values we need to sort, in the order we initially get it, and an empty stack 'B' that we can use to sort them. One of the permitted operations allows us to move (pop) an element from the top of one of the two stack and put (push) it on the top of the other one.
We need to write a program, that perform this sorting operation and give as an output not the sorted stack, but the exact sequence of operations we performed to sort the values in the queue.
It's not the actual number of operations that count, but the operations printed by the program to sort the 'stack'. The project title "Push_Swap" refers to the core operations used in this data sorting exercise. It's important to note that the actual goal of the program is not to sort the integers in the first 'stack', but to print the operations necessary to sort them. The elements of the array in memory could remain unsorted! This lead to a particular conception of this project lies in its use of a modified concept of time complexity.

### TODO

We have at our disposal two "stack" or data collection structures. The first one is supposed to hold the integer values that we need to sort. We will get the integer values as arguments of our program, and we are supposed to fill the first stack with the given integers values. The second 'stack' is an empty stack, that we can use to sort the values hold in the first stack.

- Explain in details why the data structure we have to our disposal is not a 'pure' stack.

### Makefile

- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

- I wrote a lot of commentaries in the Makefile itself. Move the commentaries from the Makefile to her.

[X] Write a Makefile
[] Write a Makefile that import libft.

#### `:=` instead of `=`

- `:=` the value of the variable is fixed and can't be changed during the executioin of make. Is a good practice to use `:=` instead `=` for variables which values don't change during the execution

#### make -C libft

The make -C command is used to execute make in a subdirectory

## Glossary

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

**Disclaimer:** This code has been written the "The Norm" of 42, which is a set of strict coding style rules. It aims to ensure consistency and readability of the codebase.

The following are some of the principal rules enforced by the Norm:

1. **Indentation**: Code should be indented using four spaces for each level of indentation to enhance clarity and maintain a consistent visual structure.

2. **Function Length**: Functions should be kept concise, containing no more than twenty-five lines of code. This practice helps to manage complexity and improves code readability.

3. **Naming Conventions**: Variables, functions, and files should be named with precision and brevity, following the recommended naming conventions. This promotes code understandability and consistency.

4. **Headers**: Each source file should include a header at the beginning, providing essential information such as the author's name, the project's name, and a brief description of its purpose.

5. **Forbidden Acts**: The Norm restricts the use of certain language features, such as `for` or `goto` statements, to ensure code quality and discourage potential pitfalls.

While adhering to the Norm may initially present challenges, it fosters discipline and order in coding practices, resulting in clean and well-structured code. Embrace the Norm, and let it guide you towards creating code that is both functional and aesthetically pleasing.

_Note: The Norm of 42 is specific to the 42 coding school, but its principles and best practices can be valuable in professional software development environments as well._
