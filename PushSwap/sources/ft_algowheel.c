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

/*static void ft_minmax(t_stack *stack)
{	
	size_t i;

	i = 0;
	while(stack->b[i] != stack->low)
		i++;
	if(i > (stack->index_b / 2))
	{
		while(stack->b[0] != stack->low)
			rotate(stack, 'b');
	}
	else
	{
		while(stack->b[0] != stack->low)
			revrotate(stack, 'b');
	}
	if(stack->a[0] > stack->max)
		stack->max = stack->a[0];
	else if(stack->a[0] < stack->low)
		stack->low = stack->a[0];
}*/

void ft_algowheel(t_stack *stack)
{
	size_t i;
	//int j = 5;
	int k;
	int non;


	/*if(stack->a[0] > stack->max | stack->a[0] < stack->low)
	{
		printf("ENTRO\n");
		ft_minmax(stack);
		return ;
	}	*/
	i = 0;
	while(stack->a[0] < stack->b[i])
		i++;
	if (!i)
		non = 1;
	else
		i--;
	k = stack->b[i];
	printf("%zu\n", i);
	if(i > (stack->index_b / 2) || non == 1)
	{
		printf("%d,  %d\n", stack->b[stack->index_b - 1], k);
		while(stack->b[0] != k)
			rotate(stack, 'b');
	}
	else
		while(stack->b[stack->index_b - 1] != k)
			revrotate(stack, 'b');
	push_b(stack);
}

