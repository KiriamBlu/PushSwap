/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:01 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:18:16 by jsanfeli         ###   ########.fr       */
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
	stack->low = ft_get_numlow(stack->a, stack->index_a);
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		stack->low = ft_get_numlow(stack->a, stack->index_a);
		i++;
	}
	twoshort(stack, 'b');
	twoshort(stack, 'a');
	ft_print_list(stack);
	aftershort(stack);
}

void fiveshort(t_stack *stack)
{
	int i;

	i = 0;
	stack->low = ft_get_numlow(stack->a, stack->index_a);
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		stack->low = ft_get_numlow(stack->a, stack->index_a);
		i++;
	}
	twoshort(stack, 'b');
	threeshort_a(stack);
	ft_print_list(stack);
	aftershort(stack);
}

void sixshort(t_stack *stack, t_ch *chunk)
{
	int i;

	i = 0;
	getdonechunk(stack, chunk, stack->index_a);
	while(stack->index_a > 3)
	{	
		if(find_bestforpivot(stack->a, chunk->pivot) == -1)
			while(stack->a[0] > chunk->pivot)
				rotate(stack, 'a');
		else
			while(stack->a[0] > chunk->pivot)
				revrotate(stack, 'a');
		push_b(stack);
		i++;
	}
	threeshort_a(stack);
	threeshort_b(stack);
	ft_print_list(stack);
	aftershort(stack);
}
