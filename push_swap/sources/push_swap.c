#include "ps_header.h"

int main(int argc, char const **argv)
{
	t_stack		a;
	size_t		j;
	//t_stack	b;

	j = ft_mount_list(argc, argv, &a);
	ft_print_list(&a);
	printf("%lu\n", j);
	//ft_args_managment(argc, argv);
	return 0;
}
/*
void ft_args_managment(int argc, char const **argv)
{
	if (argc == 1)
		exit (0);
	ft_mount_list(argc, argv, a);
	if (ft_error(argc, argv) == -1)
		ft_error_message();
}

void	ft_error_message(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

*/