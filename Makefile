# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 17:31:43 by llonnrot          #+#    #+#              #
#    Updated: 2022/02/24 17:36:34 by llonnrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = termindle

SOURCES = prog.c

FLAGS = -Wextra -Werror -Wall

LIBFT = libft.a

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@gcc $(FLAGS) $(SOURCES) -o $(NAME) $(LIBFT)

fclean:
	@echo "Removing executable..."
	@rm $(NAME)

re: fclean all