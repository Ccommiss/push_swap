# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:59:42 by ccommiss          #+#    #+#              #
#    Updated: 2021/06/01 14:36:47 by ccommiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	rotate.c \
	push.c \
	print_arrays.c \
	compute.c \
	check_functions.c \
	sort_three.c \
	move_blocks.c \
	divide_stacks.c \
	init.c \
	divide_stack_a.c \
	move_blocks_2.c ##alter 

FLAGS = -Wall -Werror -Wextra -fsanitize=address
OBJS = $(SRCS:.c=.o)
CC = clang -g $(FLAGS)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all
