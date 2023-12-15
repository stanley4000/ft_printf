# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoehn-h <skoehn-h@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 19:18:19 by skoehn-h          #+#    #+#              #
#    Updated: 2023/12/05 19:54:15 by skoehn-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

CC =	cc

CCFLAGS =	-Wall -Wextra -Werror

FILES =	ft_printf ft_putchar ft_puthex ft_putnbr \
			ft_putptr ft_putstr

SRC_DIR = srcs/
SRC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ_DIR = srcs/
OBJ =	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $^

%.o:	%.c ft_printf.h
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
