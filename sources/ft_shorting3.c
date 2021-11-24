/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:27:24 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/23 15:34:33 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int is_not_intmp(int stack, int *tmp, size_t l)
{
	size_t i;
	int s;

	i = 0;
	s = stack;
	if(l != 0)
	{	
		while(i < l)
		{
			if(stack == tmp[i])
				return(-1);
			i++;
		}
	}
	return(1);
}
static size_t getspace(int *stack, int *tmp, size_t chunksize, size_t l)
{
	size_t space;
	size_t i;
	size_t k;

	i = 0;	
	space = chunksize;
	while(i < chunksize)
	{
		k = 0;
		while(k < l)
		{
			if (stack[i] == tmp[k])
				space = space - 1;
			k++;
		}
		i++;
	}
	return(space);
}

static int ft_get_max(int *stack, int *aux,size_t chunksize, size_t l)
{
	size_t i;
	size_t tmp;
	size_t space;
	size_t check;

	i = 0;
	space = chunksize;
	while(i < chunksize)
	{
		check = 0;
		tmp = 0;
		if(is_not_intmp(stack[i], aux, l) == 1)
		{
			space = getspace(stack, aux, chunksize, l);
			while(tmp < chunksize)
			{
				if (stack[i] >= stack[tmp])
					check++;
				if(check == space)
					return(stack[i]);
				tmp++;
			}
		}
		i++;
	}
	return(0);
}


static int ft_get_min(int *stack, int *aux,size_t chunksize, size_t l)
{
	size_t i;
	size_t tmp;
	size_t space;
	size_t check;

	i = 0;
	space = chunksize;
	while(i < chunksize)
	{
		check = 0;
		tmp = 0;
		if(is_not_intmp(stack[i], aux, l) == 1)
		{
			space = getspace(stack, aux, chunksize, l);
			while(tmp < chunksize)
			{
				if (stack[i] <= stack[tmp])
					check++;
				if(check == space)
					return(stack[i]);
				tmp++;
			}
		}
		i++;
	}
	return(0);
}
int getpositionpivot(size_t chunksize, int *stack)
{
	int pivot;
	int *chunk;

	pivot = 0;
	chunk = getdonechunk(stack, chunksize, 0);
	if(chunksize % 2 == 0)
		pivot = chunk[chunksize / 2 - 1];
	else
		pivot = chunk[(chunksize / 2)];
	free(chunk);
	return (pivot);
}

int *getdonechunk(int *stack, size_t chunksize, int sign)
{
	int *aux;
	size_t i;

	i = 0;
	aux = malloc(sizeof(int) * chunksize);
	if(sign == 1)
		while (i < chunksize)
		{
			aux[i] = ft_get_max(stack, aux, chunksize, i);
			i++;
		}
	else
		while (i < chunksize)
		{
			aux[i] = ft_get_min(stack, aux, chunksize, i);
			i++;
		}
	return(aux);
}





















