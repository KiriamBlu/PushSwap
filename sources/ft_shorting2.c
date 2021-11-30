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

static size_t findereal(int aux, int *stack, size_t index)
{
	size_t i;

	i = 0;
	while(stack[i] != aux && i < index - 1)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static size_t resetaux(size_t l, t_stack *stack)
{	
	size_t m;

	m = 0;
	l = l + 2;
	while(stack->aux_a[m])
	{
		stack->aux_a[m] = 0;
		m++;
	}
	return(l);
}

static size_t *getpositions(t_stack *stack, int pivot, int s, size_t *a)
{
	size_t count;
	size_t i;
	size_t l;
	size_t position;
	size_t trueposition;
	size_t tmp;

	l = 1;
	count = 0;
	while(count < stack->index_a - 1)
	{
		position = geta(stack, pivot, count, s);
		if(position > 2147483647)
			break;
		stack->aux_a[count] = stack->a[position];
		trueposition = position;
		i = getb(stack, stack->a[position], count);
		tmp = findereal(stack->aux[i], stack->b, stack->index_b);
		if (tmp < ((stack->index_b / 2 - (stack->index_b / 3) - l) - 1) || tmp > ((stack->index_b / 2 + (stack->index_b / 3) + l) - 1))
			break;
		if(count == l)
		{
			l = resetaux(l, stack);
			count = 0;
		}
		count++;
	}
	a[0] = trueposition;
	a[1] = tmp;
	return(a); //AQUI ESTAS JOAN
}

void recursiveshortforlong(t_stack *stack)
{
	static int s;
	int pivot;
	int numa;
	int numb;	
	size_t z;
	size_t *a;

	pivot = getpositionpivot(stack->index_a, stack->a);
	if(stack->index_b == 3)
		s = find_bestforpivot(stack->a, pivot, stack->index_a);
	z = 0;
	while(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1 || z < ((stack->index_a/50)*10))
	{
		a = malloc(sizeof(size_t) * 2);
		a = getpositions(stack, pivot, s, a);
		numa = stack->a[a[0]];
		numb = stack->b[a[1]];
		dodoble(stack, a[0], a[1]);
		free(a);
		ft_prepa(stack, numa);
		ft_algowheel(stack, numb);
		z++;
	}
	if(stack->index_a != 1)
		recursiveshortforlong(stack);
}

static size_t geti(int numa, int *aux, size_t stack)
{
	size_t i;

	i = 0;
	while(numa < aux[i] && i < stack)
		i++;
	if(i == 0)
		i = stack - 1;
	return(i);
}


void recursiveshort(t_stack *stack)
{
	int pivot;
	size_t i;
	size_t position;
	int *aux;
	int numa;

	pivot = getpositionpivot(stack->index_a, stack->a);
	while(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1)
	{
		if(stack->index_a != 1)
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
	if(stack->index_a != 1)
		recursiveshort(stack);
}


void longshort(t_stack *stack)
{
	int i;

	i = 0;
	/////////////////////////////////////////////////////
	push_b(stack);
	push_b(stack);
	push_b(stack);
	threeshort_b(stack);
	while(i < 3)
	{
		stack->aux[i] = stack->b[i];
		i++;
	}
	stack->low = stack->b[2];
	stack->max = stack->b[0];
	//ft_print_list(stack);
	///////////////////////////////////////////////////////
	if(stack->index_a < 250)
		recursiveshort(stack);
	else
		recursiveshortforlong(stack);
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

