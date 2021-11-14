/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algowheel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:41:00 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/12 16:49:46 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void ft_minmax(t_stack *stack)
{	
	size_t i;

	i = 0;
	while(stack->b[i] != stack->low)
		i++;
	printf("%zu\n", i);
	if(i > (stack->index_b / 2))
		while(stack->b[stack->index_b - 1] != stack->low)
			rotate(stack, 'b');
	else
		while(stack->b[stack->index_b - 1] != stack->low)
			revrotate(stack, 'b');
	if(stack->a[0] > stack->max)
		stack->max = stack->a[0];
	else if(stack->a[0] < stack->low)
		stack->low = stack->a[0];
	push_b(stack);
}

void ft_algowheel(t_stack *stack, t_ch *chunk)
{
	size_t i;
	int k;
	int non;

	if(stack->a[0] > stack->max | stack->a[0] < stack->low)
	{
		ft_minmax(stack);
		return ;
	}
	i = 0;
	getdonechunk(stack, chunk, stack->index_b);
	while(stack->a[0] < chunk->ch[i])
		i++;
	if (!i)
		non = 1;
	else
		i--;	
	k = chunk->ch[i];
	if(i > (stack->index_b / 2) || non == 1)
		while(stack->b[0] != k)
			revrotate(stack, 'b');
	else
		while(stack->b[stack->index_b - 1] != k)
			rotate(stack, 'b');
	push_b(stack);
}

