/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:01 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:19 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	aftershort(t_stack *stack)
{
	while(stack->index_b > 0)
	{
		push_a(stack);
		stack->index_b--;
	}
}

void fourshort(t_stack *stack)
{
	int i;

	i = 0;
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		ft_get_numlow(stack);
		i++;
	}
	twoshort(stack, 'b');
	twoshort(stack, 'a');
	stack->index_b += i;
	aftershort(stack);
}

void fiveshort(t_stack *stack)
{
	int i;

	i = 0;
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		ft_get_numlow(stack);
		i++;
	}
	twoshort(stack, 'b');
	threeshort_a(stack);
	stack->index_b += i;
	aftershort(stack);
}

static size_t getpositionlowerpivot(int *a, int pivot, size_t l)
{
	size_t i;

	i = 0;
	while(i < l)
	{
		if(a[i] <= pivot)
			return(i);
		i++;
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
	if(stack->index_a != 0)
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
			
			ft_prepa(stack, numa);
			ft_algowheel(stack, chunk, i);
		}
		recursiveshort(stack, chunk);
	}
}

void longshort(t_stack *stack, t_ch *chunk)
{
	/////////////////////////////////////////////////////
	push_b(stack);
	push_b(stack);
	push_b(stack);
	threeshort_b(stack);
	stack->low = stack->b[2];
	stack->max = stack->b[0];
	//ft_print_list(stack);
	///////////////////////////////////////////////////////
	recursiveshort( stack, chunk);
	///////////////////////////////////////////////////////
	if(find_best(stack->b, stack->max, stack->index_b) == 1)
		while(stack->b[0] != stack->max)
			rotate(stack, 'b');
		else
			while(stack->b[0] != stack->max)
				revrotate(stack, 'b');
	while(stack->index_b != 0)
		push_a(stack);
	//ft_print_list(stack);
	////////////////////////////////////////////////////////
}
