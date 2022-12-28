# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2022/12/28 02:34:11 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### PRESETTINGS ####################
NAME		=	libftprintf.a
LIBFT		=	libft/
SRCS_DIR	=	sources/
SRCB_DIR	=	sources_bonus/
H_DIR		=	includes/

# Default
_END	=	\x1b[0m
_BOLD	=	\x1b[1m

# Colors
_CYAN	=	\x1b[36m

# Backgrounds
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IPURPLE	=	\x1b[45m


#################### SOURCES / OBJECTS ####################
SRCS_FILES	=	sources/print.c ft_printf.c
SRCB_FILES	=	sources_bonus/flags_bonus.c sources_bonus/print_bonus.c ft_printf_bonus.c

OBJS	=	${SRCS_FILES:.c=.o}
OBJB	=	${SRCB_FILES:.c=.o}

ifdef BONUS_OK
OBJ	=	${OBJS}
else
OBJ	=	${OBJB}
endif


#################### COMPILER ####################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

ifndef BONUS_OK
%.o:%.c	${H_DIR}ft_printf.h
		${CC} ${CFLAGS} -c -I ./${H_DIR}ft_printf.h ${SRCB_FILES} -o ${SRCB_FILES:.c=.o}
else
%.o:%.c	${H_DIR}ft_printf_bonus.h
		${CC} ${CFLAGS} -c -I ./${H_DIR}ft_printf_bonus.h ${SRCS_FILES} -o ${SRCS_FILES:.c=.o}
endif

#################### RULES ####################
all:		${NAME}

${NAME}:	${OBJ}
		@make bonus -C ${LIBFT}
		@cp libft/libft.a ${NAME}
		@ar rcs ${NAME} ${OBJ}
		@echo "${_BOLD}${_IGREEN}${_CYAN}Nicely compiled, t'es chaud${_END}"

bonus:
		@${MAKE} BONUS_OK=1

clean:
		rm -f ${OBJS} ${OBJB}
		make clean -C ${LIBFT}
		@echo "${_BOLD}${_IPURPLE}.o files destroyed${_END}"

fclean:		clean
		rm -f ${NAME}
		rm -f ${LIBFT}/libft.a
		@echo "${_BOLD}${_IRED}.a files destroyed${_END}"

re:			fclean all

.PHONY: all clean fclean re