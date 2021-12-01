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
	
	ft_get_numlow(stack);
	if(find_best(stack->a, stack->low, stack->index_a) == 1)
		while(stack->a[0] != stack->low)
			rotate(stack, 'a');
	else
		while(stack->a[0] != stack->low)
			revrotate(stack, 'a');
	push_b(stack);
	threeshort_a(stack);
	push_a(stack);
}

void fiveshort(t_stack *stack)
{
	int i;

	i = 0;
	ft_get_numlow(stack);
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
	push_a(stack);
	push_a(stack);
	push_a(stack);
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

static int checkaux(int *aux_a, int num, size_t pru)
{
	size_t l;

	l = 0;
	if(pru != 0)
	{	
		while(l < pru)
		{
			if(aux_a[l] == num)
				return(-1);
			l++;
		}
	}
	return(1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

static size_t getlowerpivotforlong(t_stack *stack, int pivot, int m, size_t pru)
{
	size_t i;

	i = 0;
	if (m == -1)
	{
		while(i < stack->index_a)
		{
			if(stack->a[i] <= pivot && checkaux(stack->aux_a, stack->a[i], pru) == 1)
				return(i);
			i++;
		}
	}
	else
	{
		i = stack->index_a - 1;
		while(i > 0)
		{
			if(stack->a[i] <= pivot && checkaux(stack->aux_a, stack->a[i], pru) == 1)
					return(i);
		i--;
		}
	}
	return(2147483648);
}

size_t getb(t_stack *stack, int numa, size_t count)
{
	int *temp;
	size_t i;

	temp = NULL;
	if(stack->index_b > 3 && count == 0)
	{
		i = 0;
		temp = getdonechunkforaux(stack->aux, stack->index_b, stack->b[0]);
			while(i < stack->index_b)
			{
				if(temp[i] != stack->aux[i])
					stack->aux[i] = temp[i];
				i++;
			}
			free(temp);
	}
	i = 0;
	while(numa < stack->aux[i] && i < stack->index_b)
		i++;
	return(i);
}

int geta(t_stack *stack, int pivot, size_t pru, int s)
{
	size_t position;

	position = 0;
	if(stack->index_a != 1)
		position = getlowerpivotforlong(stack, pivot, s, pru);
	else
		position = 0;
	return(position);
}

/////////////////////////////////////////////////////////////////////////////////////////////

static size_t *resetaux(size_t *l, t_stack *stack)
{	
	size_t m;

	m = 0;
	l[0] = l[0] + 1;
	l[1] = 0;
	while(stack->aux_a[m])
	{
		stack->aux_a[m] = 0;
		m++;
	}
	return(l);
}

static size_t *getpositions(t_stack *stack, int pivot, int s, size_t *a)
{
	size_t i;
	size_t *l;
	size_t position;

	l = ft_calloc(sizeof(size_t), 2);
	a = malloc(sizeof(size_t) * 2);
	while(l[1] < stack->index_a - 1)
	{
		position = geta(stack, pivot, l[1], s);
		if(position > 2147483647)
			break;
		stack->aux_a[l[1]] = stack->a[position];
		a[0] = position;
		i = getb(stack, stack->a[position], l[1]);
		a[1] = findereal(stack->aux[i], stack->b, stack->index_b);
		if (a[1] < ((stack->index_b / 2 - (stack->index_b / 3) - l[0]) - 1) 
			|| a[1] > ((stack->index_b / 2 + (stack->index_b / 3) + l[0]) - 1))
			break;
		if(l[1] == l[0])
			l = resetaux(l, stack);
		l[1]++;
	}
	free(l);
	return(a);
}

void recursiveshortforlong(t_stack *stack)
{
	static int s;
	int pivot;
	int num[2];
	size_t z[2];
	size_t *a;

	z[0] = 0;
	z[1] = (stack->index_a/3);
	pivot = getpositionpivot(stack->index_a, stack->a);
	if(stack->index_b == 3)
		s = find_bestforpivot(stack->a, pivot, stack->index_a);
	while(z[0] <= z[1] && numlowerpiv(stack->a, pivot, stack->index_a) == 1
		&& stack->index_a != 5)
	{
		a = getpositions(stack, pivot, s, a);
		num[0] = stack->a[a[0]];
		num[1] = stack->b[a[1]];
		dodoble(stack, a[0], a[1]);
		free(a);
		ft_prepa(stack, num[0]);
		ft_algowheel(stack, num[1]);
		z[0]++;
	}
	if(stack->index_a != 5)
		recursiveshortforlong(stack);
}

/////////////////////////////////////////////////////////////////////////////////////////////




