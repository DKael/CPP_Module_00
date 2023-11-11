# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 20:30:42 by hyungdki          #+#    #+#              #
#    Updated: 2023/11/11 13:56:31 by hyungdki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	megaphone.cpp
		
OBJS = 	${SRCS:.cpp=.o}

TOTAL_OBJS = ${OBJS}

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

${NAME} : ${TOTAL_OBJS}
	${CC} ${CFLAGS} ${TOTAL_OBJS} -o $@

%.o :%.cpp
	${CC} ${CFLAGS} -c -I. $< -o $@

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	make clean
	rm -rf ${NAME}

re: 
	make fclean
	make all

.PHONY: all clean fclean re
