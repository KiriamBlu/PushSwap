/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mount_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:35:36 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/02 17:44:34 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*static size_t	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

void	free_table(char **table)
{
	int	pos;

	pos = 0;
	while (table[pos])
	{
		free(table[pos]);
		pos++;
	}
	free(table);
	table = NULL;
}

void ft_mount_list(int argc, char const **argv, t_stack *stack)
{
	char	**ls;
	int		pos;
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
		argv = argv + 1;
		ls = ft_split((char *)*argv, ' ');
		pos = 0;
		while(ls[pos])
			stack->a[j++]  = ft_atoi(ls[pos++]);
		free_table(ls);
	}
	stack->index_a = j;
	return ;
}

void ft_print_list(t_stack *stack)
{
	size_t aux;

	aux = 0;
	while(aux < stack->index_a)
		printf("[%d]\n", stack->a[aux++]);
}





