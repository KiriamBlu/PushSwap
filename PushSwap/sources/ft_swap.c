/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:18:13 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/05 11:46:01 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void swap(t_stack *stack, int c)
{
	int i;

	if(c == 'a'&& stack->index_a > 1)
	{
		printf("sa\n");
		i = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = i;
	}
	else if(c == 'b' && stack->index_b > 1)
	{
		printf("sb\n");
		i = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = i;
	}
	else if(c == 's' && stack->index_b > 1 && stack->index_a > 1)
	{
		printf("ss\n");
		i = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = i;
		i = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = i;
	}
}