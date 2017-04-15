# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/03/22 18:22:00 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = minishell
LIB = ft
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall

PATH_SRC = ./srcs/
PATH_LB =./libft/

LIST_SRC = $(shell cat $(PATH_SRC)list_c)

FILES_SRC = $(addprefix $(PATH_SRC),$(LIST_SRC))

SRC_O = $(FILES_SRC:.c=.o)

all: list $(NAME)

title :
	@echo $(GRN)"\n---- [ Minishell ] ----"$(RST)

.c.o:
	@gcc -I./includes/ -I/usr/local/ -c $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

list : 
	@cd $(PATH_SRC) ; sh makeList.sh

$(LIBN) :
	@make -C $(PATH_LB)

$(NAME): $(LIBN) $(SRC_O)
	@gcc $(FLAGS) -I./includes/ -lcurses -L$(PATH_LB) -l$(LIB) $(SRC_O) -o $(NAME)
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
