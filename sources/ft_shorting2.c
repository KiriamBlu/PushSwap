 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:25:01 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:19 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	aftershort(t_stack *stack)
{
	while(stack->index_b > 0)
	{
		push_a(stack);
		stack->index_b--;
	}
}

void fourshort(t_stack *stack)
{
	int i;

	i = 0;
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		ft_get_numlow(stack);
		i++;
	}
	twoshort(stack, 'b');
	twoshort(stack, 'a');
	stack->index_b += i;
	aftershort(stack);
}

void fiveshort(t_stack *stack)
{
	int i;

	i = 0;
	while(i < 2)
	{	
		if(find_best(stack->a, stack->low, stack->index_a) == 1)
			while(stack->a[0] != stack->low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != stack->low)
				revrotate(stack, 'a');
		push_b(stack);
		ft_get_numlow(stack);
		i++;
	}
	twoshort(stack, 'b');
	threeshort_a(stack);
	stack->index_b += i;
	aftershort(stack);
}

static size_t getlowerpivot(int *a, int pivot, size_t l, int m)
{
	size_t i;

	i = 0;
	if (m == -1)
	{
		while(i < l)
		{
			if(a[i] <= pivot)
				return(i);
			i++;
		}
	}
	else
	{
		i = l - 1;
		while(i > 0)
		{
			if(a[i] <= pivot)
				return(i);
			i--;
		}
	}	
	return(-404);
}

static size_t findereal(int aux, int *stack, size_t index)
{
	size_t i;

	i = 0;
	while(stack[i] != aux && i < index)
		i++;
	return(i);
}

void dodoble(t_stack *stack, size_t position, size_t aux)
{
	int a;
	int b;
	int auxa;
	int auxb;

	a = find_best(stack->a, stack->a[position], stack->index_a);
	b = find_best(stack->b, stack->b[aux], stack->index_b);
	auxa = stack->a[position];
	auxb = stack->b[aux];
	if(stack->a[0] != stack->a[position] && stack->b[0] != stack->b[aux])
	{
		if(a == 1 && b == 1)
			while(stack->a[0] != auxa && stack->b[0] != auxb)
				rrotate(stack);
		else if(a == -1 && b == -1)
			while(stack->a[0] != auxa && stack->b[0] != auxb)
					rrevrotate(stack);
	}
}

void recursiveshort(t_stack *stack)
{
	int pivot;
	size_t i;
	size_t position;
	int *aux;
	int numa;

	i = 0;
	pivot = getpositionpivot(stack->index_a, stack->a);
	if(stack->index_a != 0)
	{
		position = 0;
		while(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1)
		{
			if(stack->index_a != 1)
				position = getlowerpivot(stack->a, pivot, stack->index_a, -1);
			else
				position = 0;
			numa = stack->a[position];
			aux = getdonechunk(stack->b, stack->index_b, 1);
			i = 0;
			while(numa < aux[i] && i < stack->index_b)
				i++;
			if(i == 0)
				i = stack->index_b - 1;
			dodoble(stack, position, findereal(aux[i], stack->b, stack->index_b));
			ft_prepa(stack, numa);
			ft_algowheel(stack, aux[i]);
			//ft_print_list(stack);
			free(aux);
		}
		recursiveshort(stack);
	}
}

void longshort(t_stack *stack)
{
	/////////////////////////////////////////////////////
	push_b(stack);
	push_b(stack);
	push_b(stack);
	threeshort_b(stack);
	stack->low = stack->b[2];
	stack->max = stack->b[0];
	//ft_print_list(stack);
	///////////////////////////////////////////////////////
	recursiveshort(stack);
	///////////////////////////////////////////////////////
	if(find_best(stack->b, stack->max, stack->index_b) == 1)
		while(stack->b[0] != stack->max)
			rotate(stack, 'b');
		else
			while(stack->b[0] != stack->max)
				revrotate(stack, 'b');
	while(stack->index_b != 0)
		push_a(stack);
	//ft_print_list(stack);
	////////////////////////////////////////////////////////
}

