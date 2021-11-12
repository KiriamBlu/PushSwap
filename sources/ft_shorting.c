/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:45:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:16:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void ft_shorting(t_stack *stack, t_ch *chunk)
{
	getdonechunk(stack, chunk, stack->index_a);
	if (stack->index_a >= 2 && stack->index_a <= 6)
		smallshort(stack, chunk);
	else
	{
		preparelong(stack, chunk);
		longshort(stack);
	}
	return ;
}

void smallshort(t_stack *stack, t_ch *chunk)
{
	int i;

	i = 0;
	if(stack->index_a == 2)
		twoshort(stack, 'a');
	if(stack->index_a == 3)
		threeshort_a(stack);
	if(stack->index_a == 4)
		fourshort(stack);
	if(stack->index_a == 5)
		fiveshort(stack);
	if(stack->index_a == 6)
		sixshort(stack, chunk);
}

void twoshort(t_stack *stack, int c)
{
	if(c == 'a')
		if(stack->a[0] > stack->a[1])
			swap(stack, 'a');
	if(c == 'b')
		if(stack->b[0] < stack->b[1])
			swap(stack, 'b');
}

void threeshort_a(t_stack *stack)
{
	if(stack->a[0] > stack->a[1] && stack->a[1]  > stack->a[2])
	{
		swap(stack, 'a');
		revrotate(stack, 'a');
	}
	else if(stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] 
		&& stack->a[0] < stack->a[2])
		swap(stack, 'a');
	else if(stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] 
		&& stack->a[0] > stack->a[2])
		rotate(stack, 'a');
	else if(stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] 
		&& stack->a[0] > stack->a[2])
		revrotate(stack, 'a');
	else if(stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] 
		&& stack->a[0] < stack->a[2])
	{
		revrotate(stack,'a');
		swap(stack, 'a');
	}
}

void threeshort_b(t_stack *stack)
{	
	if(stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] 
		&& stack->b[0] < stack->b[2])
		revrotate(stack, 'b');
	else if(stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] 
		&& stack->b[0] > stack->b[2])
	{
		revrotate(stack, 'b');
		swap(stack, 'b');
	}
	else if(stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] 
		&& stack->b[0] > stack->b[2])
		swap(stack, 'b');
	else if(stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] 
		&& stack->b[0] < stack->b[2])
	rotate(stack, 'b');
}





