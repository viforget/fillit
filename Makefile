# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medenis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 18:28:47 by medenis           #+#    #+#              #
#    Updated: 2019/02/10 02:24:39 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_normalize.c\
		main.c\
		ft_paint.c\
		ft_checkerror.c\
		ft_algo.c\
		ft_cleantab.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		@make -C libft/ all clean
		@gcc -c $(SRC)
		@gcc -o $(NAME) $(OBJ) libft/libft.a
		@echo "\033[32mCOMPILATION FILLIT OK\033[0m"

clean :
		@/bin/rm -f $(OBJ)
		@make -C libft/ fclean
		@echo "\033[36mCLEAN FILLIT OK\033[0m"

fclean :
		@/bin/rm -f $(OBJ) $(NAME)
		@make -C libft/ fclean
		@echo "\033[36mCLEAN FILLIT OK\033[0m"

re : fclean all

.PHONY: all clean fclean re
