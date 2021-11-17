/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:27:24 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:18 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static size_t findpositionmax(t_stack *stack)
{
	size_t i;

	i = 0;
	while(stack->b[i] != stack->max)
		i++;
	return(i);
}
static void	ft_strdup_struct(const int *b, t_stack *aux, size_t index_b)
{
	size_t	i;

	i = 0;
	aux->b = malloc(sizeof(int) * index_b);
	aux->index_b = index_b;
	while(i < index_b)
	{
		aux->b[i] = b[i];
		i++;
	}
}

void getdonechunk(t_stack *stack, t_ch *chunk, size_t chunksize)
{
	t_stack aux;
	size_t i;
	size_t u;
	size_t	aux_ch;

	i = 0;
	u = 0;
	if(chunk->pivot)
		free(chunk->ch);
	chunk->ch = malloc(sizeof(int) * chunksize);
	ft_strdup_struct(stack->b, &aux, chunksize);
	aux_ch = chunksize;
	while (i < chunksize)
	{
		ft_get_nummax(&aux);
		chunk->ch[i] = aux.max;
		chunk->index_ch++;
		u = findpositionmax(&aux);
		while(u < aux.index_b && aux.b[u + 1])
			{
				aux.b[u] = aux.b[u + 1];
				u++;
			}
		aux.index_b--;
		i++;
	}
	free (aux.b);
}






















