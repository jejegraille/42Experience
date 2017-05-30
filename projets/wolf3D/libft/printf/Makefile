# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 18:03:01 by jgraille          #+#    #+#              #
#    Updated: 2017/01/18 13:16:52 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Werror -Wextra -Wall
FILES= $(shell cat list_c)

OBJ	= $(FILES:.c=.o)

all: objet

.c.o:
	gcc -c $(FLAGS) $<

objet : $(OBJ)

clean :
	@rm -rf $(OBJ)
	@echo "clean success"

fclean : clean
	@echo "clean success"

re : fclean all
