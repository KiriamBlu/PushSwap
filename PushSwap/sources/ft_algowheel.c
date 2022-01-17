/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algowheel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:41:00 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/06 17:08:39 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	ft_minmax(t_stack *stack)
{	
	size_t	i;

	i = 0;
	while (stack->b[i] != stack->low)
		i++;
	if (i < ((stack->index_b / 2) - 1))
		while (stack->b[0] != stack->max)
			rotate(stack, 'b');
	else
		while (stack->b[0] != stack->max)
			revrotate(stack, 'b');
	if (stack->a[0] > stack->max)
		stack->max = stack->a[0];
	else if (stack->a[0] < stack->low)
		stack->low = stack->a[0];
	push_b(stack);
}

static size_t	find_k(int k, int *stack)
{
	size_t	i;

	i = 0;
	while (stack[i] != k)
		i++;
	return (i);
}

void	ft_algowheel(t_stack *stack, int k)
{
	if (stack->a[0] > stack->max | stack->a[0] < stack->low)
	{
		ft_minmax(stack);
		return ;
	}
	if (find_k(k, stack->b) < ((stack->index_b / 2) - 1))
		while (stack->b[0] != k)
			rotate(stack, 'b');
	else
	{
		while (stack->b[0] != k)
			revrotate(stack, 'b');
	}
	push_b(stack);
}

void	ft_prepa(t_stack *stack, int	position)
{
	if (find_k(position, stack->a) < (stack->index_a / 2))
		while (stack->a[0] != position)
			rotate(stack, 'a');
	else
		while (stack->a[0] != position)
			revrotate(stack, 'a');
}

void	dodoble(t_stack *stack, size_t	position, size_t aux)
{
	int	a;
	int	b;
	int	auxa;
	int	auxb;

	a = find_best(stack->a, stack->a[position], stack->index_a);
	b = find_best(stack->b, stack->b[aux], stack->index_b);
	auxa = stack->a[position];
	auxb = stack->b[aux];
	if (stack->a[0] != stack->a[position] && stack->b[0] != stack->b[aux])
	{
		if (a == 1 && b == 1)
			while (stack->a[0] != auxa && stack->b[0] != auxb)
				rrotate(stack);
		else if (a == -1 && b == -1)
			while (stack->a[0] != auxa && stack->b[0] != auxb)
				rrevrotate(stack);
	}
}