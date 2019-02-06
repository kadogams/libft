# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skadogam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 15:03:00 by skadogam          #+#    #+#              #
#    Updated: 2018/10/03 17:27:36 by skadogam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./includes
LIB = ./libft
LIB_HEADERS = ./libft/includes
FLAGS = -Wall -Wextra -Werror
SRC = ft_convert_char.c\
		ft_convert_nbr.c\
		ft_convert_size.c\
		ft_convert_type.c\
		ft_convert_type2.c\
		ft_convert_wchar_v2.c\
		ft_flags.c\
		ft_init_stuff.c\
		ft_printf.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@make re -C $(LIB)
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER) -I $(LIB_HEADERS)
	@ar rc $(NAME) $(OBJ) $(LIB)/*.o
	@ranlib $(NAME)
	@echo "\033[32mOutfile LIBFTPRINTF	[ ✔ ]"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C $(LIB)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re
