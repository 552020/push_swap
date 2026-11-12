# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:37:58 by slombard          #+#    #+#              #
#    Updated: 2023/04/16 23:47:53 by slombard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

# 'NAME' is a variable in Makefile that is commonly used to specifiy the name of the executable taht is being built. `NAME` is not a recipe or a rule, but a simple variable. The $(NAME) reference is expanded to the value of NAME.

NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

INCLUDES = -I$(INC_DIR) -Ilibft -Ift_printf

SOURCES = push_swap.c ft_swap.c ft_rotate.c ft_push.c ft_utils.c ft_utils_input_check.c ft_utils_input_check_two.c ft_count_sort.c ft_small_sort.c ft_push_next.c ft_find_scores.c ft_print_stack.c ft_atol_max_min.c

# Subsitution reference. The value/s of the SOURCE is 'expanded' with .o instead of .c, and each object goes to $(OBJ_DIR).

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

LIBFT = libft/libft.a
LIBFTPRINTF = ft_printf/libftprintf.a

# We need to have an all rule.

all: $(NAME)

# This is the first target listed in the Makefile. When we call `make` withouth specifying any rule it will run the first rule it finds.

$(NAME): $(OBJECTS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) -Llibft -lft -Lft_printf -lftprintf -o $@

$(LIBFT):
	$(MAKE) -C libft

$(LIBFTPRINTF):
	$(MAKE) -C ft_printf

# This is a pattern rule. It is not completely clear to my how this rule is tied to $(OBJECTS). This is based on the so called 'dependencies resolution algorithm'. If the make program sees that a rule is depending from certain files, it will look in Makefile itself, if there are rules to resolve it.
# If we have other .c files in the directory which are not specified in the SOURCES variable they will not be build as object files. And we could have different rules to build the different object files.
# $< means the 'first prerequsite in the rule' in our case the .c file
# $@ means the target of the rule in this case the .o file

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f libft/*.o
	rm -f ft_printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(LIBFTPRINTF)

re: fclean all

run: $(NAME)
	./$(NAME) $(ARG)

.PHONY: all clean fclean re run
