/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortingforlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:29 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:17 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int decidemiddle(int m)
{
	if(m > 0)
		return(-1);
	else
		return(1);
}

int find_bestforpivot(int *a, int c, size_t l)
{
	int m;
	unsigned long j;
	
	j = 0;
	m = 0;
	while(a[j])
	{
		if((l % 2) == 0)
		{
			if(a[j] <= c && j < (l/2))
				m++;
			else if(a[j] <= c && j > (l/2))
				m--;
		}
		else
		{
			if(a[j] < c && j < (l/2))
				m++;
			else if(a[j] < c && j > (l/2))
				m--;
		}
		j++;
	}
	return(decidemiddle(m));
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

static size_t getpositionlowerpivot(int *a, int pivot, size_t l)
{
	size_t i;

	if(find_bestforpivot(a, pivot, l) == -1)
	{
		i = 0;
		while(i < l)
		{
			if(a[i] <= pivot)
				return(i);
			i++;
		}
	}
	else
	{
		i = l - 1;
		while(i > 0)
		{
			if(a[i] <= pivot)
				return(i);
			i--;
		}
	}
	return(-404);
}

void recursiveshort(t_stack *stack, t_ch *chunk)
{
	int pivot;
	size_t i;
	size_t position;
	int numa;

	i = 0;
	pivot = getdonechunk_a(stack, stack->index_a);
	while(stack->index_a != 0)
	{
		position = 0;
		if(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1)
		{
			if(stack->index_a != 1)
				position = getpositionlowerpivot(stack->a, pivot, stack->index_a);
			else
				position = 0;
			getdonechunk(stack, chunk, stack->index_b);
			i = 0;
			while(stack->a[position] < chunk->ch[i])
				i++;
			if(i == 0)
			i = stack->index_b;
			else	
				i--;
			numa = stack->a[position];
			ft_getargsready(position, i, stack);
			ft_prepa(stack, pivot, numa);
			ft_algowheel(stack, chunk, i);
			ft_print_list(stack);
		}
		else
			recursiveshort(stack, chunk);
	}
}








