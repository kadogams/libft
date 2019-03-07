# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/22 15:56:22 by adefonta          #+#    #+#              #
#    Updated: 2019/02/22 10:39:36 by skadogam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

CC = gcc

IN =

FLAG = -O3 -fsanitize=address #-Wall -Werror -Wextra

D_SRC = srcs

D_OUT = tmp

INC = -I includes -I libft/includes -I minilibx/

INC_LIB = -lft -L./libft -lmlx -L./minilibx

OBJS = $(addprefix $(D_OUT)/,$(IN:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) #lib $(OBJS)
	@$(CC) $(OBJS) $(INC_LIB) $(FLAG) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[32mCorewar compiled  [ ✔ ]"

$(D_OUT)/%.o: $(D_SRC)/%.c
	@mkdir -p $(D_OUT)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

lib:
	@make -C libft/ fclean && make -C libft/
	@make -C minilibx/ fclean && make -C minilibx/

clean: #ib_clean
	@rm -rf $(D_OUT)
	@echo "\033[32mCorewar Clean  [ ✔ ]"

fclean: clean #lib_fclean
	@rm -f $(NAME)
	@echo "\033[32mCorewar Fclean  [ ✔ ]"

lib_clean:
	@make -C libft/ clean
	@make -C minilibx/ clean
	@echo "\033[32mLib clean [ ✔ ]"

lib_fclean: #lib_clean
	@make -C libft/ fclean
	@make -C minilibx/ fclean
	@echo "\033[32mLib Fclean [ ✔ ]"

re: fclean all

c: clean
f: fclean
r: re

.PHONY : all, clean, fclean, re
