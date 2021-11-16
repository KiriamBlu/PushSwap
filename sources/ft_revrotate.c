/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:57:03 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/16 09:46:10 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void revrotate(t_stack *stack, int c)
{
	int i;
	size_t aux;

	if(c == 'a'&& stack->index_a > 1)
	{
		printf("rra\n");
		aux = stack->index_a;
		i = stack->a[--aux];
		while(aux > 0)
		{
			stack->a[aux] = stack->a[aux - 1];
			aux--;
		}
		stack->a[0] = i;
	}
	else if(c == 'b'&& stack->index_b > 1)
	{
		printf("rrb\n");
		aux = stack->index_b;
		i = stack->b[--aux];
		while(aux > 0)
		{
			stack->b[aux] = stack->b[aux - 1];
			aux--;
		}
		stack->b[0] = i;
	}
}

void rrevrotate(t_stack *stack)
{
	int i;
	size_t aux;

	if(stack->index_b > 1 && stack->index_a > 1)
	{
		printf("rrr\n");
		aux = stack->index_a;
		i = stack->a[--aux];
		while(aux > 0)
		{
			stack->a[aux] = stack->a[aux - 1];
			aux--;
		}
		stack->a[0] = i;
		aux = stack->index_b;
		i = stack->b[--aux];
		while(aux > 0)
		{
			stack->b[aux] = stack->b[aux - 1];
			aux--;
		}
		stack->b[0] = i;
	}
}