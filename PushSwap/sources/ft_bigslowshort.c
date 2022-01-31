/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigslowshort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:13:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/31 17:38:07 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	prepa(t_stack *stack, size_t pos)
{
	int num;

	num = stack->a[pos];
	if (pos < stack->index_a/2)
		while (stack->a[0] != num)
			rotate(stack, 'a');
	else
		while (stack->a[0] != num)
			revrotate(stack, 'a');
}

void	prepb(t_stack *stack, size_t pos)
{
	int num;

	num = stack->b[pos];
	if (pos < stack->index_b/2)
		while (stack->b[0] != num)
			rotate(stack, 'b');
	else
		while (stack->b[0] != num)
			revrotate(stack, 'b');
}


void get_numsdone(int *stack, int index)
{
	int i;
	int j;
	int num;
	int *aux;

	i = 0;
	aux = malloc(sizeof(int) * index);
	while(i < index)
	{
		j = 0;
		num = 0;
		while(j < index)
		{
			if (stack[i] > stack[j])
				num++;
			j++;
		}
		aux[i] = num;
		i++;
	}
	i = -1;
	while(++i < index)
		stack[i] = aux[i];
	free(aux);
}

size_t	getpos(int *stack, size_t index, int num)
{
	size_t j;
	size_t i;
	size_t l;

	i = index - 1;
	j = 0;
	while(j < index)
	{
		if(stack[j] < num)
			break ;
		j++;
	}
	while(i > 0)
	{
		if(stack[i] < num)
			break ;
		i--;
	}
	l = index - i;
	if(l < j)
		return(i);
	else
		return(j);
}

size_t	getnum(int *stack, size_t index, int num)
{
	size_t j;
	size_t i;
	size_t l;

	i = index - 1;
	j = 0;
	while(j < index)
	{
		if(stack[j] == num)
			break ;
		j++;
	}
	while(i > 0)
	{
		if(stack[i] == num)
			break ;
		i--;
	}
	l = index - i;
	if(l < j)
		return(i);
	else
		return(j);
}


static void makechunk(t_stack *stack, size_t chunk)
{
	size_t		i;

	i = 0;
	while(i < 40 && stack->index_a != 0)
	{
		prepa(stack, getpos(stack->a, stack->index_a, chunk));
		push_b(stack);
		if(stack->b[0] < stack->b[1])
			swap(stack, 'b');
		i++;
	}
}

void	recursiveshortforlong(t_stack *stack)
{
	size_t chunksize;

	chunksize = 40;
	get_numsdone(stack->a, (int)stack->index_a);
	while(stack->index_a != 0)
	{
		makechunk(stack ,chunksize);
		chunksize += 40;
	}
	while(stack->index_b != 0)
	{
		prepb(stack, getnum(stack->b, stack->index_b, stack->index_b - 1));
		push_a(stack);
	}
}

