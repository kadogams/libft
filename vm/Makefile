# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclecler <aclecler@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 00:39:00 by aclecler          #+#    #+#              #
#    Updated: 2019/03/12 19:18:18 by adefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

FLAGS = -O3 -Wall -Wextra -Werror #-fsanitize=address

IN =	vm.c champi.c error.c pc.c free.c init.c arena.c operation.c\
		args.c tools.c dump.c put.c put2.c flags.c verbosity.c introduction.c \
		parser.c

OP =	op_live.c op_ld.c op_st.c op_add.c op_sub.c op_and.c op_or.c op_xor.c \
		op_zjmp.c op_ldi.c op_sti.c op_fork.c op_lld.c op_lldi.c op_lfork.c \
		op_aff.c

IN_VISU = 	visu.c mlx.c colors.c event.c del.c image.c extra.c display_1.c \
			display_2.c graph.c load.c display_tools.c graph_display.c

LIBFT = ../libftprintf

SRCS_DIR = srcs

OP_DIR = $(SRCS_DIR)/ops

SRCS_DIR_VISU = visu/srcs

OUT_DIR = tmp

INC =	-Iincludes -I$(LIBFT)/includes/ -I$(LIBFT)/libft/includes \
		-Ivisu/includes -Ivisu/minilibx/

INC_LIB =  -lmlx -L./visu/minilibx $(LIBFT)/libftprintf.a -L$(LIBFT)

SRCS = $(addprefix $(SRCS_DIR)/,$(IN)) $(addprefix $(OP_DIR)/,$(OP))

SRCS_VISU = $(addprefix $(SRCS_DIR_VISU)/,$(IN_VISU))

OBJS = $(addprefix $(OUT_DIR)/,$(IN:.c=.o)) $(addprefix $(OUT_DIR)/,$(OP:.c=.o))

OBJS_VISU = $(addprefix $(OUT_DIR)/,$(IN_VISU:.c=.o))

all: $(NAME)


$(NAME): lib $(OBJS) $(OBJS_VISU)
	@$(CC) $(OBJS) $(OBJS_VISU) $(INC_LIB) $(FLAGS) -framework OpenGL -framework AppKit -o $(NAME)
	@cp $(NAME) ../
	@echo "\033[32mCorewar compiled	[ ✔ ]"

$(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(SRCS_DIR_VISU)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(OP_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

lib:
	@make -C $(LIBFT)
	@make -C visu/minilibx/

norme:
	norminette ./$(LIBFT)/ ./$(INC)/ ./$(SRCS_DIR)/
	@echo

clean:
	@rm -f $(OBJS)
	@rm -rf $(OUT_DIR)
	@make clean -C $(LIBFT)
	@make -C visu/minilibx/ clean
	@echo "\033[32mVM clean  [ ✔ ]"

fclean: clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@make fclean -C $(LIBFT)
	@make -C visu/minilibx/ fclean
	@echo "\033[32mVM fclean  [ ✔ ]"

re: fclean all

f: fclean
r: re
c: clean
