# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/02/12 10:54:47 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = fdf
LIB = ft
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall

PATH_FD = ./srcs/
PATH_LB =./libft/

LIST_FD = $(shell cat $(PATH_FD)list_c)

FILES_FD = $(addprefix $(PATH_FD),$(LIST_FD))

SRC_O = $(FILES_FD:.c=.o)

all: list $(NAME)

title :
	@echo $(GRN)"\n---- [ FDF ] ----"$(RST)

.c.o:
	@gcc -I./includes/ -I/usr/local/ -c $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

list : 
	@cd $(PATH_FD) ; sh makeList.sh

$(LIBN) :
	@make -C $(PATH_LB)

$(NAME): $(LIBN) $(SRC_O)
	@gcc $(FLAGS) -I./includes/ -I/usr/local/ -L/usr/local/ -lmlx -framework OpenGL -framework AppKit -L$(PATH_LB) -l$(LIB) $(SRC_O) -o $(NAME)
	@echo $(GRN)"[CREATE] "$(RST)$(NAME)

mmlx :
	man mlx -M man

mmlx_w :
	man mlx_new_window -M man

mmlx_l :
	man mlx_loop -M man

mmlx_p :
	man mlx_pixel_put -M man

mmlx_i :
	man mlx_new_image -M man

clean :
	@make clean -C $(PATH_LB)
	@rm -rf $(SRC_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@make fclean -C $(PATH_LB)
	@rm -rf $(NAME)
	@echo $(RED)"[DEL] "$(RST)$(NAME)

re : fclean all
