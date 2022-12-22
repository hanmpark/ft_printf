# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2022/12/22 13:06:47 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES
NAME		=	libftprintf.a
LIBFT		=	libft/
SRCS_DIR	=	sources/
H_DIR		=	includes/

# This is a minimal set of ANSI/VT100 color codes
_END	=	\x1b[0m
_BOLD	=	\x1b[1m

# Colors
_CYAN		=	\x1b[36m

# Inverted, i.e. colored backgrounds
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IPURPLE	=	\x1b[45m

# SOURCES / OBJECTS
SRCS_FILES	=	type_stdout.c treat_flags_str.c flags_parsing.c
SRCS		=	${addprefix ${SRCS_DIR}, ${SRCS_FILES}} ft_printf.c

OBJS		=	${SRCS:.c=.o}

# COMPILER

CC			= gcc
#CFLAGS		= -Wall -Wextra -Werror
%.o:%.c		${H_DIR}
		${CC} ${CFLAGS} -c -I ./${H_DIR} $< -o ${<:.c=.o}

# MAKE
all:		${NAME}

${NAME}:	${OBJS}
		@make bonus -C ${LIBFT}
		@cp libft/libft.a ${NAME}
		@ar rcs ${NAME} ${OBJS}
		@echo "${_BOLD}${_IGREEN}${_CYAN}Nicely compiled, t'es chaud${_END}"

#	RULES
clean:
		rm -f ${OBJS}
		make clean -C ${LIBFT}
		@echo "${_BOLD}${_IPURPLE}.o files destroyed${_END}"

fclean:		clean
		rm -f ${NAME}
		rm -f ${LIBFT}/libft.a
		@echo "${_BOLD}${_IRED}.a files destroyed${_END}"

re:			fclean all

.PHONY: all clean fclean re