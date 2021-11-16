/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:45:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/16 10:32:18 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void ft_shorting(t_stack *stack, t_ch *chunk)
{
	if (stack->index_a >= 2 && stack->index_a <= 5)
		smallshort(stack);
	else
	{
		chunk->ch = NULL;
		longshort(stack, chunk);
	}
	return ;
}

void smallshort(t_stack *stack)
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
	else if(stack->b[0] < stack->b[1] && stack->b[1] < stack->b[2] 
		&& stack->b[0] < stack->b[2])
		{
			swap(stack, 'b');
			revrotate(stack, 'b');
		}
}

int find_best(int *a, int c, size_t l)
{
	int i;
	unsigned long j;
	
	i = 0;
	j = 0;
	while(a[j] != c)
		j++;
	if (j >= (l / 2))
		return(-1);
	else
		return(1);
}




