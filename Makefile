# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 09:02:04 by nguiard           #+#    #+#              #
#    Updated: 2023/04/24 20:35:58 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_strlen.s	\
	srcs/ft_strcpy.s	\
	srcs/ft_strcmp.s	\
	srcs/ft_write.s		\
	srcs/ft_read.s		\
	srcs/ft_strdup.s	\

OBJ = ${SRC:.s=.o}

NAME = libasm.a

NAME_TEST = test.out

.s.o:
	nasm -f elf64 $< -o ${<:.s=.o}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${OBJ} ${NAME} ${NAME_TEST}

test: ${NAME}
	@gcc -Wall -Werror -Wextra -g3 tests/test.c ${NAME} -o ${NAME_TEST}
	@./${NAME_TEST}

unit: ${NAME}
	@gcc -Wall -Werror -Wextra -g3 tests/test.c ${NAME} -o ${NAME_TEST}
	@./${NAME_TEST} unit 2>/dev/null 0>/dev/null

re: fclean ${NAME}

.PHONY: re fclean clean all test unit