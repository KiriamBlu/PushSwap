/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mount_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:35:36 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/02 16:17:13 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void ft_mount_list(int argc, char const **argv, t_stack *stack)
{
	char	**ls;
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	stack->a = malloc(sizeof(t_stack));
	if (!stack->a)
	{
		free(stack->a);
		exit(0);
	}
	while (i++ < argc)
	{
		printf("esto es argv:%s_________y esta es su direccion:%p\n ", *argv, *argv);
		argv = argv + 1;
		ls = ft_split((char *)*argv, ' ');
		while(*ls)
		{
			stack->a[j]  = ft_atoi(*ls);
			free(*ls);
			ls++;
			j++;
		}
	}
	system("leaks push_swap");
	stack->index_a = j;
	if (ft_get_no_dup(stack) == -1)
		ft_error_message();
	return ;
}

void ft_print_list(t_stack *stack)
{
	size_t aux;

	aux = 0;
	while(aux < stack->index_a)
		printf("[%d]\n", stack->a[aux++]);
}





