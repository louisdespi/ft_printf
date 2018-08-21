# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 13:43:39 by lode-spi          #+#    #+#              #
#    Updated: 2018/07/30 15:38:39 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = test
INCLUDES = -Iincludes/
LIB = -Llibft/
SRC = ft_printf.c list.c main.c specifiers_1.c parse_format.c helper.c
OBJ = $(SRC:.c=.o)
BIN = $(wildcard ./bin/*.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(BIN) $(LIB) -lft

%.o: src/%.c
	@$(CC) -o ./bin/$@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)

re : fclean all
