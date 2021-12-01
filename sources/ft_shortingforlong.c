/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortingforlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:29 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/01 17:27:15 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int decidemiddle(int m)
{
	if(m < 0)
		return(1);
	else
		return(-1);
}

int  find_bestforpivot(int *a, int c, size_t l)
{
	int m;
	unsigned long j;
	
	j = 0;
	m = 0;
	while(a[j])
	{
		if((l % 2) == 0)
		{
			if(a[j] <= c && j < (l/2))
				m++;
			else if(a[j] <= c && j > (l/2))
				m--;
		}
		else
		{
			if(a[j] < c && j < (l/2))
				m++;
			else if(a[j] < c && j > (l/2))
				m--;
		}
		j++;
	}
	return(decidemiddle(m));
}

size_t findereal(int aux, int *stack, size_t index)
{
	size_t i;

	i = 0;
	while(stack[i] != aux && i < index - 1)
		i++;
	return(i);
}

void	ft_get_numlow(t_stack *stack)
{
	t_stack *aux;
	size_t check;
	size_t count;
	size_t tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_a)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while(tmp < stack->index_a)
		{
			if (stack->a[count] <= aux->a[tmp])
				check++;
			if(check == stack->index_a)
				stack->low = stack->a[count];
			tmp++;
		}
		count++;
	}
	return ;
}

void	ft_get_nummax(t_stack *stack)
{
	t_stack *aux;
	size_t check;
	size_t count;
	size_t tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_b)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while(tmp < stack->index_b)
		{
			if (stack->b[count] >= aux->b[tmp])
				check++;
			if(check == stack->index_b)
				stack->max = stack->b[count];
			tmp++;
		}
		count++;
	}
	return ;
}