# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:37:58 by slombard          #+#    #+#              #
#    Updated: 2023/02/20 14:55:12 by slombard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c
# Subsitution reference. The value/s of the SOURCE is 'expanded' with .o instead of .c. If we have just a file push_swap in the directory where we call make than instead of this rule we could just write OBJECTS = push_swap.o
OBJECTS = $(SOURCES:.c=.o)

# 'NAME' is a variable in Makefile that is commonly used to specifiy the name of the executable taht is being built. `NAME` is not a recipe or a rule, but a simple variable. The $(NAME) reference is expanded to the value of NAME. 
NAME = push_swap

# This is the first target listed in the Makefile. When we call `make` withouth specifying any rule it will run the first rule it finds. If we have just one file let's say push_swap.c in the directory where we call make we could write this rule as `push_swap: push_swap.o`.
$(NAME): $(OBJECTS)

# This is a pattern rule. It is not completely clear to my how this rule is tied to $(OBJECTS). This is based on the so called 'dependencies resolution algorithm'. If the make program sees that a rule is depending from certain files, it will look in Makefile itself, if there are rules to resolve it. 
# If we have other .c files in the directory which are not specified in the SOURCES variable they will not be build as object files. And we could have different rules to build the different object files. 
# $< means the 'first prerequsite in the rule' in our case the .o file
# $@ means the target of the rule in this case the .c file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


