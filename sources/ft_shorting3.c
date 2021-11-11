/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:27:24 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/11 10:51:17 by jsanfeli         ###   ########.fr       */
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
static void	ft_strdup_struct(const int *a, t_stack *aux, size_t index_a)
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
static void getpositionpivot(size_t chunksize, t_ch *chunk)
{
	if(chunksize % 2 == 0)
		chunk->pivot = chunk->ch[chunksize / 2 - 1];
	else
		chunk->pivot = chunk->ch[(chunksize / 2)];
	chunk->index_ch = chunksize;
}

void getdonechunk(t_stack *stack, t_ch *chunk, size_t chunksize)
{
	t_stack aux;
	size_t i;
	size_t u;

	i = 0;
	u = 0;
	if(chunk->index_ch != 0)
		free(chunk->ch);
	chunk->ch = malloc(sizeof(int) * chunksize);
	ft_strdup_struct(stack->a, &aux, chunksize);
	while (i < chunksize)
	{
		ft_get_numlow(&aux);
		chunk->ch[i] = aux.low;
		u = findpositionlow(&aux);
		while(u < aux.index_a && aux.a[u + 1])
		{
			aux.a[u] = aux.a[u + 1];
			u++;
		}
		aux.index_a--;
		i++;
	}
	getpositionpivot(chunksize, chunk);
	free (aux.a);
}

void	ft_get_numlow(t_stack *stack)
{
	t_stack *aux;
	size_t check;
	size_t count;
	size_t tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_a)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while(tmp < stack->index_a)
		{
			if (stack->a[count] <= aux->a[tmp])
				check++;
			if(check == stack->index_a)
				stack->low = stack->a[count];
			tmp++;
		}
		count++;
	}
	return ;
}

int find_best(int *a, int c, size_t l)
{
	int i;
	unsigned long j;
	
	i = 0;
	j = 0;
	while(a[j] != c)
		j++;
	if (j >= (l / 2))
		return(-1);
	else
		return(1);
}




















