/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:46 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/16 14:52:01 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static size_t findpositionlow(t_stack *stack)
{
	size_t i;

	i = 0;
	while(stack->a[i] != stack->low)
		i++;
	return(i);
}
static void	ft_strdup_struct_A(const int *a, t_stack *aux, size_t index_a)
{
	size_t	i;

	i = 0;
	aux->a = malloc(sizeof(int) * index_a);
	aux->index_a = index_a;
	while(i < index_a)
	{
		aux->a[i] = a[i];
		i++;
	}
}

int getpositionpivot(size_t chunksize, t_ch *chunk)
{
	int pivot;

	pivot = 0;
	if(chunksize % 2 == 0)
		pivot = chunk->ch[chunksize / 2 - 1];
	else
		pivot = chunk->ch[(chunksize / 2)];
	free(chunk->ch);
	return (pivot);
}

int getdonechunk_a(t_stack *stack, size_t chunksize)
{
	t_stack	aux;
	t_ch	chunk;
	size_t i;
	size_t u;

	i = 0;
	u = 0;
	chunk.ch = NULL;
	chunk.index_ch = chunksize;
	chunk.ch = malloc(sizeof(int) * chunksize);
	ft_strdup_struct_A(stack->a, &aux, chunksize);
	while (i < chunksize)
	{
		ft_get_numlow(&aux);
		chunk.ch[i] = aux.low;
		u = findpositionlow(&aux);
		while(u < aux.index_a && aux.a[u + 1])
		{
			aux.a[u] = aux.a[u + 1];
			u++;
		}
		aux.index_a--;
		i++;
	}
	free (aux.a);
	return(getpositionpivot(chunksize, &chunk));
}