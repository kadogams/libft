# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclecler <aclecler@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 00:39:00 by aclecler          #+#    #+#              #
#    Updated: 2019/02/12 14:38:01 by adefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

#FLAGS = -O3 -Wall -Wextra -Werror

IN =	vm.c

LIBFT = ../libftprintf

SRCS_DIR = srcs

OUT_DIR = tmp

INC = -I includes -I ../libftprintf/includes/ -I $(LIBFT)/libft/includes


SRCS_LEMIN = $(addprefix $(SRCS_DIR)/,$(IN))

OBJS_LEMIN = $(addprefix $(OUT_DIR)/,$(IN:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_LEMIN)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $^ -o $@ -I $(LIBFT)/libft/$(INC) -I $(LIBFT)/$(INC) $(LIBFT)/libftprintf.a
	@echo "\033[32mOutfile COREWAR	[ ✔ ]"

$(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

norme:
	norminette ./$(LIBFT)/ ./$(INC)/ ./$(SRCS_DIR)/
	@echo

clean:
	@rm -f $(OBJS_LEMIN)
	@rm -rf $(OUT_DIR)
	@make clean -C $(LIBFT)
	@echo "\033[32mClean  [ ✔ ]"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[32mFclean  [ ✔ ]"

re: fclean all
m : fclean main

f: fclean
r: re
c: clean
