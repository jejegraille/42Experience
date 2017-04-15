# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/03/22 18:16:53 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = libft.a
FLAGS = -Werror -Wextra -Wall

PATH_LB = 
PATH_PF = printf/

LIST_LB = $(shell cat $(PATH_LB)list_c)
LIST_PF = $(shell cat $(PATH_PF)list_c)

FILES_LB = $(addprefix $(PATH_LB),$(LIST_LB))
FILES_PF = $(addprefix $(PATH_PF),$(LIST_PF))

SRC_F = $(shell echo $(FILES_LB) && echo $(FILES_PF))

SRC_O = $(SRC_F:.c=.o)

all: list $(NAME)

title :
	@echo $(GRN)"\n---- [ COMPILATION LIBFTPRINTF ] ----"$(RST)

.c.o:
	@gcc -c -I$(PATH_PF) $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o) 

list:
	@sh makeList.sh
	@cd $(PATH_PF); sh makeList.sh

$(NAME): $(SRC_O)
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)
	@echo $(GRN)"[CREATE] "$(RST)$(NAME)

clean :
	@rm -rf $(SRC_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@rm -rf $(NAME)
	@echo $(RED)"[DEL] "$(RST)$(NAME)

re : fclean all
