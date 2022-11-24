# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2022/11/23 13:40:05 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./ft_printf.c ./ft_printf_utils.c 

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o =
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

NAME		= libftprintf.a

all:		${NAME}

${NAME}:	${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

bonus:		${OBJS}
				ar rcs ${NAME} ${OBJS}

.PHONY: all clean fclean re