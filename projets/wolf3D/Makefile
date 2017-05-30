# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/05/28 17:22:19 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

PATH_W3 = ./srcs/
PATH_LX = ./libx/
PATH_LB =./libft/

W3 = wolf3D
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall
PATH_L = -L$(PATH_LB)\
		 -L/usr/local/\

PATH_I = -I./includes/\
		 -I/usr/local/\
		 -I./libx\
		 -I./libft/include\

LIBS = -lft\
	   -lmlx\
	   -lncurses\

FRAMEWORK = -framework OpenGL\
			-framework AppKit\

PARAMS = $(FLAGS) -Ofast $(PATH_I) $(PATH_L) $(LIBS) $(FRAMEWORK)

LIST_W3 = $(shell cat $(PATH_W3)list_c)
LIST_LX = $(shell cat $(PATH_LX)list_c)
FILES_W3 = $(addprefix $(PATH_W3),$(LIST_W3))
FILES_LX = $(addprefix $(PATH_LX),$(LIST_LX))
W3_O = $(FILES_W3:.c=.o)
LX_O = $(FILES_LX:.c=.o)

## MAIN ##

all: MLIB $(W3)

## MANUEL MLX ##

mlx :
	echo "mmlx_[wlpi]"

mmlx_w :
		man mlx_new_window -M man

mmlx_l :
		man mlx_loop -M man

mmlx_p :
		man mlx_pixel_put -M man

mmlx_i :
		man mlx_new_image -M man


## LIST DEPENDENCY ##

list :
	@cd $(PATH_W3) ; sh makelist.sh
	@cd $(PATH_LX) ; sh makelist.sh
	@echo $(GRN)$(W3)$(RST)" files dependency updated"
	@make list -C $(PATH_LB)

## MAKEFILE ##


.c.o:
	@gcc -c $(FLAGS) $(PATH_I) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

MLIB :
	@make -C $(PATH_LB)

$(W3): $(LIBN) $(LX_O) $(W3_O)
	@gcc $(PARAMS) $(W3_O) $(LX_O) -o $(W3)
	@echo $(GRN)"[CREATE] "$(RST)$(W3)

clean :
	@make clean -C $(PATH_LB)
	@rm -rf $(W3_O)
	@rm -rf $(LX_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@make fclean -C $(PATH_LB)
	@rm -rf $(W3)
	@echo $(RED)"[DEL] "$(RST)$(W3)

re : fclean all
