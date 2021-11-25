/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:25:40 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/25 09:41:36 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_error_message(t_stack *stack)
{
	ft_free_list(stack);
	write(1, "Error\n", 6);
	exit (0);
}

void ft_args_managment(int argc, char const **argv, t_stack *stack)
{
	size_t	j;

	j = 0;
	if (argc == 1)
		exit (0);
	ft_mount_list(argc, argv, stack);
	ft_get_numlow(stack);
	if(ft_check_sign(argc, argv) == -1)
		ft_error_message(stack);
	if (ft_get_nothing_else_num(argc, argv) == -1)
		ft_error_message(stack);
	if (ft_get_no_dup(stack) == -1)
		ft_error_message(stack);
	if(ft_not_short(stack) == -1)
		exit(0);
	return ;
}

void	ft_free_list(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->aux);
	free(stack->aux_a);
	return ;
}

int main(int argc, char const **argv)
{
	t_stack		stack;

	ft_args_managment(argc, argv, &stack);
	//printf("START\n");
	//ft_print_list(&stack);
	ft_shorting(&stack);
	//ft_print_list(&stack);
	ft_free_list(&stack);
	//system("leaks push_swap");
	return 0;
}

