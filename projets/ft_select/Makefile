# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/03/29 10:40:51 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = ft_select
LIB = ft
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall

PATH_SRC = ./srcs/
PATH_LB =./libft/

LIST_SRC = $(shell cat $(PATH_SRC)list_c)
LIST_LB = $(shell cat $(PATH_LB)list_c)

FILES_SRC = $(addprefix $(PATH_SRC),$(LIST_SRC))
FILES_LB = $(addprefix $(PATH_LB),$(LIST_LB))

SRC_O = $(FILES_SRC:.c=.o)
LB_O = $(FILES_LB:.c=.o)

all: $(LIBN) $(NAME)

list :
	@cd $(PATH_SRC) ; sh makelist.sh
	@make list -C $(PATH_LB)
	@echo $(GRN)$(NAME)$(RST)" files dependency updated"

.c.o:
	@gcc -I./includes/ -I/usr/local/ -c $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

$(LIBN) : $(LB_O)
	@make -C $(PATH_LB)

$(NAME): $(LIBN) $(SRC_O)
	@gcc $(FLAGS) -I./includes/ -L$(PATH_LB) -lncurses -l$(LIB) $(SRC_O) -o $(NAME)
	@echo $(GRN)"[CREATE] "$(RST)$(NAME)

clean :
	@rm -rf $(LB_O)
	@rm -rf $(SRC_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@make fclean -C $(PATH_LB)
	@rm -rf $(NAME)
	@echo $(RED)"[DEL] "$(RST)$(NAME)

re : fclean all
