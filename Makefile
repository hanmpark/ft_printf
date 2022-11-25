# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2022/11/25 21:48:12 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	DIRECTORIES
NAME		=	libftprintf.a
LIBFT		=	libft/
SRCS_DIR	=	sources/

# This is a minimal set of ANSI/VT100 color codes
_END	=	\x1b[0m
_BOLD	=	\x1b[1m

# Colors
_GREEN		=	\x1b[32m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_RED		=	\x1b[31m

# Inverted, i.e. colored backgrounds
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IPURPLE	=	\x1b[45m

#	SOURCES / OBJECTS
SRCS_FILES	=	ft_putchars ft_putints 
SRCS		=	${addprefix ${SRCS_DIR}, ${addsuffix .c, ${SRCS_FILES}}}

OBJS		=	${SRCS:.c=.o}

PRINTF		=	ft_printf.c

PRINTF_OBJS	=	${PRINTF:.c=.o}

#	COMPILER

CC			= gcc
#CFLAGS		= -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -c -I ./includes $< -o ${<:.c=.o}

#	MAKE
all:		${NAME}

${NAME}:	${OBJS} ${PRINTF_OBJS}
		@echo "${_GREEN}───────────────▄▄───▐█${_END}"
		@echo "${_GREEN}───▄▄▄───▄██▄──█▀───█─▄${_END}"
		@echo "${_GREEN}─▄██▀█▌─██▄▄──▐█▀▄─▐█▀${_END}"
		@echo "${_GREEN}▐█▀▀▌───▄▀▌─▌─█─▌──▌─▌${_END}"
		@echo "${_GREEN}▌▀▄─▐──▀▄─▐▄─▐▄▐▄─▐▄─▐▄${_END}"
		@make bonus -C ${LIBFT}
		@cp libft/libft.a ${NAME}
		@ar rc ${NAME} ${OBJS} ${PRINTF_OBJS}
		@echo "${_BOLD}${_IGREEN}${_CYAN}Nicely compiled, t'es chaud${_END}"

#	RULES
clean:
		rm -f ${OBJS} ${PRINTF_OBJS}
		make clean -C ${LIBFT}
		@echo "${_BOLD}${_IPURPLE}.o files destroyed${_END}"

fclean:		clean
		rm -f ${NAME}
		rm -f ${LIBFT}/libft.a
		@echo "${_BOLD}${_IRED}.a files destroyed${_END}"
		@echo "${_RED}                                                         c=====e${_END}"
		@echo "${_RED}                                                            H${_END}"
		@echo "${_RED}   ____________                                         _,,_H__${_END}"
		@echo "${_RED}  3__33__33___3                                       //|     |${_END}"
		@echo "${_RED}  3__33__33___33_____________________________________// |ACME |${_END}"
		@echo "${_RED}   3__33__33___33------------------------------------'  |_____|${_END}"

re:			fclean all

.PHONY: all clean fclean re