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
	
	ft_get_numlow(stack);
	if(find_best(stack->a, stack->low, stack->index_a) == 1)
		while(stack->a[0] != stack->low)
			rotate(stack, 'a');
	else
		while(stack->a[0] != stack->low)
			revrotate(stack, 'a');
	push_b(stack);
	threeshort_a(stack);
	push_a(stack);
}

void fiveshort(t_stack *stack)
{
	int i;

	i = 0;
	ft_get_numlow(stack);
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
	push_a(stack);
	push_a(stack);
	push_a(stack);
}

static int checkaux(int *aux_a, int num, size_t pru)
{
	size_t l;

	l = 0;
	if(pru != 0)
	{	
		while(l < pru)
		{
			if(aux_a[l] == num)
				return(-1);
			l++;
		}
	}
	return(1);
}

size_t getlowerpivotforlong(t_stack *stack, int pivot, int m, size_t pru)
{
	size_t i;

	i = 0;
	if (m == -1)
	{
		while(i < stack->index_a)
		{
			if(stack->a[i] <= pivot && checkaux(stack->aux_a, stack->a[i], pru) == 1)
				return(i);
			i++;
		}
	}
	else
	{
		i = stack->index_a - 1;
		while(i > 0)
		{
			if(stack->a[i] <= pivot && checkaux(stack->aux_a, stack->a[i], pru) == 1)
					return(i);
		i--;
		}
	}
	return(2147483648);
}
