#include "pushswap.h"

void	free_stacks(t_stacks *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
}

/*
**	Checks if a number is set twice
*/
int	check_errors(t_stacks *s)
{
	int	*copy;
	int	i;
	int	j;

	if (!ft_malloc_int_pointer(s->n_elem_a + 1, &copy))
	{
		free_stacks(s);
		exit (0);
	}
	i = -1;
	while (++i <= s->n_elem_a)
	{
		copy[i] = s->a[i];
		j = -1;
		while (++j <= i)
		{
			if (j != i && copy[j] == copy[i])
			{
				printf("Error\nTwice the same number (%d)\n", copy[j]);
				exit (0);
			}
		}
	}
	free(copy);
	return (TRUE);
}

void	fill_stack(t_stacks *s, int ac, char **argv)
{
	int	tmp;

	tmp = ac;
	while (ac >= 0)
	{
		if (ac == tmp && ft_strncmp(argv[ac], "-v", 3) == 0)
			s->verbose = TRUE;
		else if (!ft_isdigit_str(argv[ac]) || (!ft_atoi_check_limits(argv[ac])
				|| ft_strlen(argv[ac]) == 0))
		{
			if (!ft_isdigit_str(argv[ac]) || ft_strlen(argv[ac]) == 0)
				printf ("Error\nArgs must be numerics.\n");
			if (!ft_atoi_check_limits(argv[ac]))
				printf ("Error\nArgs must be between INT_MIN / INT_MAX.\n");
			free_stacks(s);
			exit(0);
		}
		else
		{
			s->n_elem_a++;
			s->a[s->n_elem_a] = ft_atoi(argv[ac]);
		}
		ac--;
	}
}

/*
**	Create stacks and init all structure items
*/
int	create_stacks(t_stacks *s, int elems)
{
	if (!ft_malloc_int_pointer(elems, &s->a)
		|| !ft_malloc_int_pointer(elems, &s->b))
	{
		free_stacks(s);
		exit (0);
	}
	s->n_elem_a = -1;
	s->n_elem_b = -1;
	s->low_chunk = 0;
	s->high_chunk = 0;
	s->index_min = -1;
	s->chunk_size = 0;
	s->op_count = 0;
	s->verbose = FALSE;
	s->pa = 0;
	s->pb = 0;
	s->sa = 0;
	s->sb = 0;
	s->ra = 0;
	s->rb = 0;
	s->rra = 0;
	s->rrb = 0;
	return (TRUE);
}
