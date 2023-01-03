# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/03 23:45:32 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### PRESETTINGS ####################
NAME		=	libftprintf.a
LIBFT		=	libft/
SRCS_DIR	=	sources/
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
SRCS_FILES	=	def_flags.c print_basic.c treat_charflags.c treat_intflags.c \
				print_hexa.c specifier_filter.c format_hexa.c
SRCS		=	${addprefix ${SRCS_DIR}, ${SRCS_FILES}} ft_printf.c

OBJS		=	${SRCS:.c=.o}

#################### COMPILER ####################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c	${H_DIR}
		${CC} ${CFLAGS} -c -I ./${H_DIR} $< -o ${<:.c=.o}

#################### RULES ####################
all:		${NAME}

${NAME}:	${OBJS}
		@echo "\n${_BOLD}${_CYAN}==================== C O M P I L I N G ====================${_END}\n"
		@make bonus -C ${LIBFT}
		@cp libft/libft.a ${NAME}
		@ar rcs ${NAME} ${OBJS}
		@echo "${_BOLD}${_IGREEN}Compiled without encountering any problem${_END}\n"

bonus:
		@${MAKE}

clean:
		@echo "${_BOLD}${_CYAN}==================== C L E A N I N G ====================${_END}\n"
		rm -f ${OBJS}
		@make clean -C ${LIBFT}
		@echo "${_BOLD}${_IPURPLE}.o files destroyed${_END}"

fclean:		clean
		rm -f ${NAME}
		rm -f ${LIBFT}/libft.a
		@echo "${_BOLD}${_IRED}.a files destroyed${_END}"

re:			fclean all

.PHONY: all clean fclean re