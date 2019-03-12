# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dazheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 13:38:06 by dazheng           #+#    #+#              #
#    Updated: 2019/03/12 13:48:31 by dazheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
NAME2 = vm

all:
	@make -C $(NAME)
	@make -C $(NAME2)

clean:
	@make clean -C $(NAME)
	@make clean -C $(NAME2)

fclean:
	@make fclean -C $(NAME)
	@make fclean -C $(NAME2)

re: fclean all

.PHONY: re clean fclean all
