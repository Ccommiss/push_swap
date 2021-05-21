void reverse_rotate_a(t_stacks *s) //le dernier elem devient le premier
{
	int tmp;
	int tmp2;
	int i;

	i = 0;
	tmp = s->stack_a[0]; //on save l'element du top de la stack

	while (i <= s->n_elem_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[s->n_elem_a] = tmp;
	print_array('A', s->stack_a, s->n_elem_a);
}

void rotate_a(t_stacks *s)
{
	int tmp;
	int i;

	i = s->n_elem_a;
	tmp = s->stack_a[s->n_elem_a]; //on save l'element du top de la stack
	while (i >= 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = tmp;
	print_array('A', s->stack_a, s->n_elem_a);
}
