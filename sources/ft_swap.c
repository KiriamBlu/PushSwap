/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:18:13 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/06 16:09:41 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	swap(t_stack *stack, int c)
{
	int	i;

	i = stack->a[0];
	if (c == 'a' && stack->index_a > 1)
	{
		printf("sa\n");
		stack->a[0] = stack->a[1];
		stack->a[1] = i;
	}
	else if (c == 'b' && stack->index_b > 1)
	{
		printf("sb\n");
		i = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = i;
	}
	else if (c == 's' && stack->index_b > 1 && stack->index_a > 1)
	{
		printf("ss\n");
		stack->a[0] = stack->a[1];
		stack->a[1] = i;
		i = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = i;
	}
}

int	*getdonechunkforaux(int *stack, size_t chunksize, int new_b)
{
	size_t	i;
	size_t	j;
	int		*aux;

	i = 0;
	aux = ft_calloc(sizeof(int), chunksize);
	while (i < chunksize - 1)
	{
		aux[i] = stack[i];
		i++;
	}
	i = 0;
	while (i < chunksize - 1 && aux[i] > new_b)
		i++;
	j = chunksize;
	while (j > i)
	{
		aux[j] = aux[j - 1];
		j--;
	}
	aux[i] = new_b;
	return (aux);
}

int	getpositionpivot(size_t chunksize, int *stack)
{
	int	pivot;
	int	*chunk;

	pivot = 0;
	chunk = getdonechunk(stack, chunksize, 0);
	if (chunksize % 2 == 0)
		pivot = chunk[chunksize / 2 - 1];
	else
		pivot = chunk[(chunksize / 2)];
	free(chunk);
	return (pivot);
}
