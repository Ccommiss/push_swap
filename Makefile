# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:59:42 by ccommiss          #+#    #+#              #
#    Updated: 2021/06/23 11:05:18 by ccommiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SRC_FOLD = ./srcs/
MOVES = $(SRC_FOLD)moves/
SORT_BACK = $(SRC_FOLD)algo_sort_and_back/
TWO_STACKS = $(SRC_FOLD)algo_two_stacks/
WEIRD = $(SRC_FOLD)algo_weird/
SORT_FUNC = $(SRC_FOLD)sort_functions/
UTILS = $(SRC_FOLD)utils/

SRCS = main.c \
	$(MOVES)rotate.c \
	$(MOVES)push.c \
	$(SORT_BACK)divide_stack_a.c \
	$(TWO_STACKS)divide_once.c \
	$(UTILS)print_arrays.c \
	$(UTILS)compute.c \
	$(SORT_FUNC)sort_three.c \
	$(SORT_FUNC)sort_check.c \
	$(WEIRD)move_blocks.c \
	$(WEIRD)divide_stacks.c \
	$(WEIRD)check_pivot.c \
	$(UTILS)init.c \
	$(SORT_FUNC)sort_ten_twenty.c \
	$(SORT_BACK)move_blocks_2.c \
	$(SORT_BACK)sort_b_on_a.c \
	$(SORT_BACK)utils.c

LIB = $(SRC_FOLD)libft
INCLUDES = /includes/
FLAGS = -I.$(INCLUDES) -I$(LIB) -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
CC = clang -g $(FLAGS)


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB)
	$(CC) $(OBJS) -L$(LIB) -lft -o $(NAME)

clean :
	make clean -C $(LIB)
	rm $(OBJS)

fclean : clean
	make fclean -C $(LIB)
	rm $(NAME)

re : fclean all
