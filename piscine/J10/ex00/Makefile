# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/20 08:34:11 by jgraille          #+#    #+#              #
#    Updated: 2016/08/20 10:55:20 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP= gcc
METHODE= -c
FLAGS= -Wall -Wextra -Werror
PATH_SRC= ./srcs/
PATH_INC= ./includes/
OUT_NAME= libft.a

all : fichier_o
	ar rc $(OUT_NAME) *.o
	ranlib $(OUT_NAME)
	
fichier_o : 
	$(COMP) $(METHODE) $(PATH_SRC)*.c $(FLAGS)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(OUT_NAME)

re : fclean all
