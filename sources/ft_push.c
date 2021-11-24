/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:09:42 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/23 14:05:01 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void push_b(t_stack *stack)
{
	size_t i;
	int num;

	num = stack->a[0];
	printf("pb\n");
	if(stack->b[0])
	{
		i = ++stack->index_b;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
	}
	else
		++stack->index_b;
	stack->b[0] = num;
	i = 0;
	stack->index_a--;
	while(i <= stack->index_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
}

void push_a(t_stack *stack)
{
	size_t i;
	int num;

	num = stack->b[0];
	printf("pa\n");
	if(stack->a[0])
	{
		i = ++stack->index_a;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
	}
	else
		++stack->index_a;
	stack->a[0] = num;
	i = 0;
	stack->index_b--;
	while(i <= stack->index_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
}
