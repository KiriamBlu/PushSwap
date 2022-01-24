/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:35:37 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/20 15:00:43 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static void	firstlong(t_stack *stack)
{
	int	i;

	i = 0;
	push_b(stack);
	push_b(stack);
	push_b(stack);
	threeshort_b(stack);
	while (i < 3)
	{
		stack->aux[i] = stack->b[i];
		i++;
	}
	stack->low = stack->b[2];
	stack->max = stack->b[0];
}

void	longshort(t_stack *stack)
{
	if(stack->index_a < 250)
	{
		firstlong(stack);
		recursiveshort(stack);
		threeshort_a(stack);
		ft_get_nummax(stack);
		if (find_best(stack->b, stack->max, stack->index_b) == 1)
			while (stack->b[0] != stack->max)
				rotate(stack, 'b');
		else
			while (stack->b[0] != stack->max)
				revrotate(stack, 'b');
		while (stack->index_b != 0)
			push_a(stack);
	}
	else
	{
		recursiveshortforlong(stack);
	}
}

static size_t	geti(int numa, int *aux, size_t stack)
{
	size_t	i;

	i = 0;
	while (numa < aux[i] && i < stack)
		i++;
	if (i == 0)
		i = stack - 1;
	return (i);
}

size_t	getlowerpivot(int *a, int pivot, size_t l, int m)
{
	size_t	i;

	i = 0;
	if (m == -1)
	{
		while (i < l)
		{
			if (a[i] <= pivot)
				return (i);
			i++;
		}
	}
	else
	{
		i = l - 1;
		while (i > 0)
		{
			if (a[i] <= pivot)
				return (i);
			i--;
		}
	}	
	return (-404);
}

void	recursiveshort(t_stack *stack)
{
	int		pivot;
	size_t	i;
	size_t	position;
	int		*aux;
	int		numa;

	pivot = getpositionpivot(stack->index_a, stack->a);
	while (numlowerpiv(stack->a, pivot, stack->index_a) == 1
		&& stack->index_a != 3)
	{
		if (stack->index_a != 1)
			position = getlowerpivot(stack->a, pivot, stack->index_a, -1);
		else
			position = 0;
		numa = stack->a[position];
		aux = getdonechunk(stack->b, stack->index_b, 1);
		i = geti(numa, aux, stack->index_b);
		dodoble(stack, position, findereal(aux[i], stack->b, stack->index_b));
		ft_prepa(stack, numa);
		ft_algowheel(stack, aux[i]);
		free(aux);
	}
	if (stack->index_a != 3)
		recursiveshort(stack);
}
