# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/02/04 20:51:16 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = ft_ls
LIB = ft
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall

PATH_LS = ./srcs/
PATH_LB =./libft/

LIST_LS = $(shell cat $(PATH_LS)list_c)

FILES_LS = $(addprefix $(PATH_LS),$(LIST_LS))

SRC_O = $(FILES_LS:.c=.o)

all: $(NAME)

title :
	@echo $(GRN)"\n---- [ COMPILATION LS ] ----"$(RST)

.c.o:
	@gcc -I./includes/ -c $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

list : 
	@cd $(PATH_LS) ; sh makeList.sh

$(LIBN) :
	@make -C $(PATH_LB)

$(NAME): $(LIBN) $(SRC_O)
	@gcc $(FLAGS) -I./includes/ -L$(PATH_LB) -l$(LIB) $(SRC_O) -o $(NAME)
	@echo $(GRN)"[CREATE] "$(RST)$(NAME)

clean :
	@make clean -C $(PATH_LB)
	@rm -rf $(SRC_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@make fclean -C $(PATH_LB)
	@rm -rf $(NAME)
	@echo $(RED)"[DEL] "$(RST)$(NAME)

re : fclean all
