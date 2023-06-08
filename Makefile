# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 18:37:48 by pdelanno          #+#    #+#              #
#    Updated: 2023/03/21 15:22:37 by pdelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_eval_format.c ft_print_char.c ft_print_str.c \
ft_print_int.c ft_print_unsignedint.c ft_print_address.c ft_print_hexalo.c \
ft_print_hexaup.c flags.c

OBJS = ${SRCS:.c=.o}

HEADERS = ft_printf.h

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra

.c.o:
						gcc ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):		${OBJS} ${HEADERS}
						ar -rcs $@ $^

all:			${NAME}

bonus:			${NAME}

clean:
						rm -f ${OBJS}

fclean:			clean
						rm -f ${NAME}

re:						fclean all

.PHONY:			all clean fclean re bonus
