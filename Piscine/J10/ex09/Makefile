# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/20 16:57:31 by jgraille          #+#    #+#              #
#    Updated: 2016/08/23 06:38:00 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP= gcc 
FLAGS= -Wall -Werror -Wextra
OUT_NAME=ft_advanced_do-op
PATH_SRC=srcs/
PATH_INC=includes/

all :
	$(COMP) $(FLAGS) -o $(OUT_NAME) $(PATH_SRC)*.c

clean :
	rm -rf *.c

fclean : clean
	rm $(OUT_NAME)

re : fclean all
