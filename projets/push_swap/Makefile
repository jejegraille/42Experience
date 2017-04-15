# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/04/02 19:29:45 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED  = "\x1B[31m"
GRN  = "\x1B[32m"
YEL  = "\x1B[33m"
RST  = "\x1B[0m"

CH = checker
PS = push_swap
LIB = ft
LIBN = libft/libft.a
FLAGS = -Werror -Wextra -Wall

PATH_OP = ./srcs/operator/
PATH_CH = ./srcs/checker/
PATH_PS = ./srcs/push_swap/
PATH_LB =./libft/

LIST_OP = $(shell cat $(PATH_OP)list_c)
LIST_CH = $(shell cat $(PATH_CH)list_c)
LIST_PS = $(shell cat $(PATH_PS)list_c)
LIST_LB = $(shell cat $(PATH_LB)list_c)

FILES_OP = $(addprefix $(PATH_OP),$(LIST_OP))
FILES_CH = $(addprefix $(PATH_CH),$(LIST_CH))
FILES_PS = $(addprefix $(PATH_PS),$(LIST_PS))
FILES_LB = $(addprefix $(PATH_LB),$(LIST_LB))

OP_O = $(FILES_OP:.c=.o)
CH_O = $(FILES_CH:.c=.o)
PS_O = $(FILES_PS:.c=.o)
LB_O = $(FILES_LB:.c=.o)

all: $(CH) $(PS)

list :
	@cd $(PATH_CH) ; sh makelist.sh
	@echo $(GRN)$(CH)$(RST)" files dependency updated"
	@cd $(PATH_PS) ; sh makelist.sh
	@echo $(GRN)$(PS)$(RST)" files dependency updated"
	@cd $(PATH_OP) ; sh makelist.sh
	@echo $(GRN)"other"$(RST)" files dependency updated"
	@make list -C $(PATH_LB)

title :
	@echo $(GRN)"\n---- [ push_swap ] ----"$(RST)

.c.o:
	@gcc -I./includes/ -c $(FLAGS) $< -o $(<:.c=.o)
	@echo $(GRN)"[CREATE] "$(RST)$(<:.c=.o)

$(LIBN) : $(LB_O)
	@make -C $(PATH_LB)

$(CH): $(LIBN) $(CH_O) $(OP_O)
	@gcc $(FLAGS) -I./includes/ -L$(PATH_LB) -l$(LIB) $(CH_O) $(OP_O) -o $(CH)
	@echo $(GRN)"[CREATE] "$(RST)$(CH)

$(PS):$(LIBN) $(PS_O) $(OP_O)
	@gcc $(FLAGS) -I./includes/ -L$(PATH_LB) -l$(LIB) $(PS_O) $(OP_O) -o $(PS)
	@echo $(GRN)"[CREATE] "$(RST)$(PS)

clean :
	@rm -rf $(LB_O)
	@rm -rf $(CH_O)
	@rm -rf $(PS_O)
	@rm -rf $(OP_O)
	@echo $(RED)"[DEL OBJETS]" $(RST)

fclean : clean
	@make fclean -C $(PATH_LB)
	@rm -rf $(CH) $(PS)
	@echo $(RED)"[DEL] "$(RST)$(CH) and $(PS)

re : fclean all
