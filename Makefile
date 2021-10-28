# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlong <jlong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 11:08:17 by jlong             #+#    #+#              #
#    Updated: 2021/10/28 17:03:04 by jlong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	source/general_untils \
				source/operation \
				source/push_back_a \
				source/stack_untils \
				source/push_swap \
				source/error \
				source/small_sort \
				source/general_untils2 \
				source/find_hold \
				source/sort_until \
				source/sort \
				source/push_b \
				source/operation_sort \

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc
RM			= rm -f
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C libft
			${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

all:		$(NAME)

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
