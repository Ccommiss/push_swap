




#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

#define reset "\e[0m"

typedef struct s_struct
{
	int		*stack_a;
	int		n_elem_a;
	int		*stack_b;
	int		n_elem_b;
}		t_stacks;


void 	print_array(char which_stack, int *stack, int top);


#endif

