# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 07:13:22 by hanmpark          #+#    #+#              #
#    Updated: 2023/04/03 11:18:28 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- COLORS ---------------------------------- #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m
LGREEN = \033[38;5;155m

# --------------------------------- SOURCES ---------------------------------- #
SRC_PATH = ./src/

SRCS = ${addprefix ${SRC_PATH}, def_flags.c \
								print_basic.c \
								treat_charflags.c \
								treat_intflags.c \
								print_hexa.c \
								specifier_filter.c \
								format_hexa.c \
								ft_printf.c}

# --------------------------------- OBJECTS ---------------------------------- #
OBJS = ${SRCS:.c=.o}

# --------------------------------- COMPILER --------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = ./inc/
SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${SRC_PATH}%.o: ${SRC_PATH}%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH} -c $< -o ${<:.c=.o}
	@echo ""
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[FT_PRINTF]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

# ---------------------------------- RULES ----------------------------------- #
LIBFT = ./libft/
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n\n\n"
	@${MAKE} -C ${LIBFT}
	@cp ${LIBFT}libft.a ${NAME}
	@ar rcs ${NAME} ${OBJS}
	@echo "\n\n\n   ${BOLD}${CUR}${LYELLOW}FT_PRINTF COMPILED ✨${DEF}\n"

bonus:
	@${MAKE}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@echo "${ORANGE}${BOLD}\tCLEANING${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted object files${DEF}"

fclean: clean
	@rm -f ${LIBFT}/libft.a ${NAME}
	@echo "${LBLUE}${BOLD}${CUR} - Deleted libft.a${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted ${NAME}${DEF}"

re: fclean all

.PHONY: all clean fclean re