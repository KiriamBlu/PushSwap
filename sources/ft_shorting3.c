/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:27:24 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/15 09:42:58 by jsanfeli         ###   ########.fr       */
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
	if(chunksize % 2 == 0)
		chunk->pivot = chunk->ch[chunksize / 2 - 1];
	else
		chunk->pivot = chunk->ch[(chunksize / 2)];
	free (aux.b);
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

void	ft_get_nummax(t_stack *stack)
{
	t_stack *aux;
	size_t check;
	size_t count;
	size_t tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_b)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while(tmp < stack->index_b)
		{
			if (stack->b[count] >= aux->b[tmp])
				check++;
			if(check == stack->index_b)
				stack->max = stack->b[count];
			tmp++;
		}
		count++;
	}
	return ;
}



















