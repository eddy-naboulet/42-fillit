# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afougere <afougere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 19:19:10 by afougere          #+#    #+#              #
#    Updated: 2016/03/28 14:40:52 by afougere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_error.c ft_move_form.c ft_place_tetri.c ft_resolve_fillit.c \
ft_verif_next.c main.c

O = ft_error.o ft_move_form.o ft_place_tetri.o ft_resolve_fillit.o \
ft_verif_next.o main.o

LIB = libft/

all: $(NAME)

$(NAME):
		@$(MAKE) -C $(LIB)
		@gcc -c -Wall -Wextra -Werror $(SRC) 
		@gcc -o $(NAME) $(O) libft/libft.a

.PHONY : clean fclean re all

clean:
		@$(MAKE) -C $(LIB) clean
		@rm -f $(O)

fclean: clean
		@$(MAKE) -C $(LIB) fclean
		@rm -f $(NAME)

re: fclean all
	@$(MAKE) -C $(LIB) re
