# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:59:42 by ccommiss          #+#    #+#              #
#    Updated: 2021/06/22 13:52:03 by ccommiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


MOVES = moves/
SORT_BACK = algo_sort_and_back/
TWO_STACKS = algo_two_stacks/
WEIRD = algo_weird/
SORT_FUNC = sort_functions/
UTILS = utils/

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

FLAGS =  -I. -Wall -Werror -Wextra -fsanitize=address
OBJS = $(SRCS:.c=.o)
CC = clang -g $(FLAGS)


all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(OBJS) -L./libft/ -lft -o $(NAME)

clean :
	make clean -C libft
	rm $(OBJS)

fclean : clean
	make fclean -C libft
	rm $(NAME)

re : fclean all
