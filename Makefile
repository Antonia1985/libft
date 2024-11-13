# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 19:19:19 by apavlopo          #+#    #+#              #
#    Updated: 2024/11/12 19:22:04 by apavlopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC = $(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
    $(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c libft.h
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)	

re: fclean all
