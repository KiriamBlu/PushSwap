#include "ps_header.h"

void	ft_error_message(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

size_t ft_args_managment(int argc, char const **argv, t_stack *a)
{
	size_t	j;

	j = 0;
	if (argc == 1)
		exit (0);
	j = ft_mount_list(argc, argv, a);
	if(ft_not_short(a) == -1)
	{
		ft_free_list(a);
		ft_error_message();
	}
	return (j);
}

void	ft_free_list(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}

int main(int argc, char const **argv)
{
	t_stack		a;
	size_t		j;
	//t_stack	b;

	j = ft_args_managment(argc, argv, &a);
	ft_print_list(&a);
	printf("%zu\n", j);
	ft_free_list(&a);
	return 0;
}

