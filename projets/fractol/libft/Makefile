# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/05/27 11:57:08 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

NAME = libft.a
FLAGS = -Werror -Wextra -Wall

PATH_LB = 
PATH_PF = ./printf/
PATH_SL = ./ft_select/

LIST_LB = $(shell cat $(PATH_LB)list_c)
LIST_PF = $(shell cat $(PATH_PF)list_c)
LIST_SL = $(shell cat $(PATH_SL)list_c)

FILES_LB = $(addprefix $(PATH_LB),$(LIST_LB))
FILES_PF = $(addprefix $(PATH_PF),$(LIST_PF))
FILES_SL = $(addprefix $(PATH_SL),$(LIST_SL))

LB_O = $(FILES_LB:.c=.o)
PF_O = $(FILES_PF:.c=.o)
SL_O = $(FILES_SL:.c=.o)

INCLUDE = "-I./include/"

all: $(NAME)

.c.o:
	@gcc -c $(INCLUDE) $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o) 

list:
	@sh makeList.sh
	@cd $(PATH_PF); sh makeList.sh
	@cd $(PATH_SL); sh makeList.sh
	@echo $(GRN)$(NAME)$(RST) files dependencys updated

$(NAME): $(LB_O) $(PF_O) $(SL_O)
	@ar rc $(NAME) $(LB_O) $(SL_O) $(PF_O)
	@ranlib $(NAME)
	@echo $(GRN)"[CREATE] "$(RST)$(NAME)

clean :
	@rm -rf $(PF_O)
	@rm -rf $(SL_O)
	@rm -rf $(LB_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@rm -rf $(NAME)
	@echo $(RED)"[DEL] "$(RST)$(NAME)

re : fclean all
