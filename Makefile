# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 09:02:04 by nguiard           #+#    #+#              #
#    Updated: 2022/04/21 12:53:28 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_strlen.s	\

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

re: fclean ${NAME}

.PHONY: re fclean clean all