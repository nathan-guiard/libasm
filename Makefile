# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 09:02:04 by nguiard           #+#    #+#              #
#    Updated: 2023/04/24 16:44:20 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_strlen.s	\
	srcs/ft_strcpy.s	\
	srcs/ft_strcmp.s	\
	srcs/ft_write.s		\
	srcs/ft_read.s		\

OBJ = ${SRC:.s=.o}

NAME = libasm.a

.s.o:
	nasm -f elf64 $< -o ${<:.s=.o}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${OBJ} ${NAME}

test: ${NAME}
	@gcc -g3 test.c ${NAME} -o test.out
	@./test.out

unit: ${NAME}
	@gcc -g3 test.c ${NAME} -o test.out
	@./test.out unit

re: fclean ${NAME}

.PHONY: re fclean clean all test unit