/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:01 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/31 18:34:12 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	aftershort(t_stack *stack)
{
	while (stack->index_b > 0)
	{
		push_a(stack);
		stack->index_b--;
	}
}

void	fourshort(t_stack *stack)
{
	ft_get_numlow(stack);
	if (find_best(stack->a, stack->low, stack->index_a) == 1)
		while (stack->a[0] != stack->low)
			rotate(stack, 'a');
	else
		while (stack->a[0] != stack->low)
			revrotate(stack, 'a');
	push_b(stack);
	threeshort_a(stack);
	push_a(stack);
}

void	fiveshort(t_stack *stack)
{
	int	i;

	i = 0;
	ft_get_numlow(stack);
	while (i < 2)
	{	
		if (find_best(stack->a, stack->low, stack->index_a) == 1)
			while (stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while (stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		ft_get_numlow(stack);
		i++;
	}
	twoshort(stack, 'b');
	threeshort_a(stack);
	push_a(stack);
	push_a(stack);
}
