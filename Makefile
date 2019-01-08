# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medenis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 18:28:47 by medenis           #+#    #+#              #
#    Updated: 2019/01/08 19:41:20 by medenis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_normalize.c\
	  	main.c\
		ft_paint.c\
		libft/libft.a\

OBJ = 

all : $(NAME)

$(NAME) :
		@gcc -Wall -Wextra -Werror -c $(SRC)
		@make -C libft/ all clean
		@echo "\033[32mCOMPILATION OK\033[0m"

clean :
		/bin/rm -f $(OBJ)
		@echo "\033[36mCLEAN OK\033[0m"

fclean :
		/bin/rm -f $(OBJ) $(NAME)
		@echo "\033[36mCLEAN OK\033[0m"

re : fclean all

.PHONY: all clean fclean re
