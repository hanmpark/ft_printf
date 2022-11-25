# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2022/11/21 18:02:29 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES 	=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c \
				ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS		= ${SOURCES:.c=.o}

BONUS 		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c 

BONUS_OBJS	= ${BONUS:.c=.o}

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

NAME		= libft.a

all:		${NAME}

${NAME}:	${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:	
				rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

bonus:		${OBJS} ${BONUS_OBJS}
				ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all clean fclean re bonus