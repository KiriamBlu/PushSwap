/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:25:40 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/02 12:48:24 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		exit(0);
	return (j);
}

void	ft_free_list(t_stack *stack)
{
	free(stack);
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
	system("leaks push_swap");
	return 0;
}

