# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2015/11/04 18:24:51 by tboos             #+#    #+#             #
#   Updated: 2015/11/05 00:11:36 by tboos            ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
NAME = fillit
FLAGS = -Wall -Wextra -Werror
S = error_free_result.c filling.c main.c map_to_solve.c tetriminos.c
SRC = $(addprefix srcs/,$(S))

all: $(NAME)

lib:
	cd libft ; make ; make clean ; mv libft.a ../.

$(NAME): lib
	gcc $(FLAGS) $(SRC) -I includes libft.a -o $(NAME)

clean:
	rm -f libft.a

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)

.PHONY: clean fclean re 
