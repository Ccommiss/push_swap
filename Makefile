# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:59:42 by ccommiss          #+#    #+#              #
#    Updated: 2021/06/17 14:56:29 by ccommiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


MOVES = moves/
SORT_BACK = algo_sort_and_back/
TWO_STACKS = algo_two_stacks/
WEIRD = algo_weird/
SORT_FUNC = sort_functions/

SRCS = main.c \
	$(MOVES)rotate.c \
	$(MOVES)push.c \
	$(SORT_BACK)divide_stack_a.c \
	$(TWO_STACKS)divide_once.c \
	print_arrays.c \
	compute.c \
	check_functions.c \
	$(SORT_FUNC)sort_three.c \
	$(SORT_FUNC)sort_check.c \
	move_blocks.c \
	$(WEIRD)divide_stacks.c \
	$(WEIRD)check_pivot.c \
	init.c \
	$(SORT_FUNC)sort_ten_twenty.c \
	$(SORT_BACK)move_blocks_2.c \
	$(SORT_BACK)sort_b_on_a.c \
	$(SORT_BACK)utils.c

FLAGS =  -I. -Wall -Werror -Wextra -fsanitize=address
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
