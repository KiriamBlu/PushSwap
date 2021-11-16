/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:01 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/16 16:39:49 by jsanfeli         ###   ########.fr       */
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

static int therearenumberlowerpivot(int *a, int pivot, size_t l)
{
	size_t i;

	i = 0;
	while(i < l)
	{
		if(a[i] <= pivot)
			return(1);
		i++;
	}
	return(0);
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

void longshort(t_stack *stack, t_ch *chunk)
{
	int pivot;

	push_b(stack);
	push_b(stack);
	push_b(stack);
	threeshort_b(stack);
	stack->low = stack->b[2];
	stack->max = stack->b[0];
	pivot = getdonechunk_a(stack, stack->index_a);
	while(stack->index_a != 0)
	{
		if(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1)
		{
			if(find_bestforpivot(stack->a, pivot, stack->index_a) == -1)
				while(stack->a[0] > pivot)
					rotate(stack, 'a');
			else
				while(stack->a[0] > pivot)
					revrotate(stack, 'a');
		}
		ft_algowheel(stack, chunk);
	}
	if(find_best(stack->b, stack->max, stack->index_b) == 1)
		while(stack->b[0] != stack->max)
			rotate(stack, 'b');
		else
			while(stack->b[0] != stack->max)
				revrotate(stack, 'b');
	while(stack->index_b != 0)
		push_a(stack);
}
