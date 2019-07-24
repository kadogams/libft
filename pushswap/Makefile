# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 14:26:59 by skadogam          #+#    #+#              #
#    Updated: 2019/07/24 21:49:53 by skadogam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOLVER = push_swap

HEADERS = includes

LIB = libftprintf

INC = -I $(HEADERS) -I $(LIB)/$(HEADERS)

INC_LIB = -L $(LIB) $(LIB)/libftprintf.a

IN = check_arg.c\
	check_op.c\
	init_stuff.c\
	operations.c\
	operations_push.c\
	operations_rotate.c\
	operations_rrotate.c\
	operations_swap.c\
	options.c\
	put_op.c\
	put_op2.c\
	put_op3.c\
	quicksort_tab.c\
	structs.c

IN_CHECKER = checker.c

IN_SOLVER = backtrack_all.c\
	backtrack_partition.c\
	deal_with_it.c\
	push_swap.c\
	sort_a_init.c\
	sort_a.c\
	sort_b.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/,$(IN))

SRCS_CHECKER = $(addprefix $(SRCS_DIR)/,$(IN_CHECKER))

SRCS_SOLVER = $(addprefix $(SRCS_DIR)/,$(IN_SOLVER))

OBJ_DIR = tmp

OBJ = $(addprefix $(OBJ_DIR)/,$(IN:.c=.o))

OBJ_CHECKER = $(addprefix $(OBJ_DIR)/,$(IN_CHECKER:.c=.o))

OBJ_SOLVER = $(addprefix $(OBJ_DIR)/,$(IN_SOLVER:.c=.o))

all: $(NAME) $(SOLVER)

$(NAME): lib $(OBJ) $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_CHECKER) $(INC_LIB) -o $(NAME)
	@echo "\033[32mChecker compiled	[ ✔ ]\e[0m"

$(SOLVER) : lib $(OBJ) $(OBJ_SOLVER)
	@$(CC) $(FLAGS) $(OBJ) $(OBJ_SOLVER) $(INC_LIB) -o $(SOLVER)
	@echo "\033[32mPush-Swap compiled	[ ✔ ]\e[0m"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

lib:
	@make -C $(LIB)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB)
	@echo "\033[32mVM clean  [ ✔ ]\e[0m"

fclean: clean
	@rm -f $(NAME) $(SOLVER)
	@make fclean -C $(LIB)
	@echo "\033[32mVM fclean  [ ✔ ]\e[0m"

re: fclean all

.PHONY: all, clean, fclean, re
