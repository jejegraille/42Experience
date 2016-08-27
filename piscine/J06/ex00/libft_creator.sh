# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/15 20:29:23 by jgraille          #+#    #+#              #
#    Updated: 2016/08/15 20:38:06 by jgraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c *.c;
ar rc libft.a *.o;
ranlib libft.a;
mkdir libft_fonction_o;
mkdir libft_fonction_c;
mkdir libft_repertory;
mv *.c libft_fonction_c;
mv *.o libft_fonction_o;
mv libft_fonction* libft_repertory;
