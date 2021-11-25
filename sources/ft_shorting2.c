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

int geta(t_stack *stack, int pivot, size_t pru)
{
	size_t position;

	position = 0;
	if((stack->index_a != 1 && (pru % 2) != 0) || pru == 0)
		position = getlowerpivotforlong(stack, pivot, -1, pru);
	else if(stack->index_a != 1 && (pru % 2) == 0 )
		position = getlowerpivotforlong(stack, pivot, 1, pru);
	else
		position = 0;
	return(position);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void recursiveshortforlong(t_stack *stack)
{
	int pivot;
	size_t count;
	size_t i;
	size_t l;
	size_t position;
	size_t trueposition;
	size_t tmp;
	size_t z;
	int numa;
	int numb;

	i = 0;
	tmp = 0;
	z = 0;
	pivot = getpositionpivot(stack->index_a, stack->a);
	if(stack->index_a != 0)
	{
		position = 0;
		while(therearenumberlowerpivot(stack->a, pivot, stack->index_a) == 1 && z != 100)
		{
			l = 3;
			count = 0;
			while(count < stack->index_a - 1)
			{
				position = geta(stack, pivot, count);
				if(position > 2147483647) /*|| position < ((stack->index_a/2 - stack->index_a/3) - 1) || position > ((stack->index_a/2 + stack->index_a/3) - 1)*/
					break;
				stack->aux_a[count] = stack->a[position];
				trueposition = position;
				numa = stack->a[position];
				i = getb(stack,  numa, count);
				tmp = findereal(stack->aux[i], stack->b, stack->index_b);
				if (tmp < ((stack->index_b / 2 - (stack->index_b / l) - 5) - 1) || tmp > ((stack->index_b / 2 + (stack->index_b / l) + 5) - 1))
					break;
				if(count == 15)
					l = l + 1;
				count++;
			}
			numb = stack->b[tmp];
			dodoble(stack, trueposition, tmp);
			ft_prepa(stack, numa);
			ft_algowheel(stack, numb);
			z++;
			//ft_print_list(stack);
		}
		//ft_print_list(stack);
		if(stack->index_a != 1)
			recursiveshortforlong(stack);
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
			if(stack->index_a != 1 && find_bestforpivot(stack->a, pivot, stack->index_a) == 1) // DECIDIR MITAD EEN LA QUE MIRAR POR ESTE -1
				position = getlowerpivot(stack->a, pivot, stack->index_a, -1);
			else if(stack->index_a != 1 && find_bestforpivot(stack->a, pivot, stack->index_a) == -1)
				getlowerpivot(stack->a, pivot, stack->index_a, -1);
			else if(stack->index_a != 1)
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

