/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortingforlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:29 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:21:26 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int decidemiddle(unsigned long j, unsigned long u, int type)
{
	if(j < u)
		return(j);
	else
	{
		if(type == 1)
			u *= -1;
		return(u);
	}
}

int find_bestforpivot(int *a, int c)
{
	unsigned long k;
	unsigned long u;
	unsigned long j;
	
	j = 0;
	k = 0;
	u = 0;
	while(a[k])
		k++;
	while(a[j] > c)
		j++;
	while(a[k] > c)
	{
		u++;
		k--;
	}
	return(decidemiddle(j, u, 1));
}

int isshortstack(int *a)
{
	int j;

	j = 0;
	while(a[j] < a[j + 1])
	{ 
		if(a[j] > a[j + 1])
			return(-1);
		j++;
	}
	return(1);
}

void preparelong(t_stack *stack, t_ch *chunk)
{
	int i;
	int j;
	size_t count;

	i = 0;
	j = 0;
	count =  stack->index_a / 2;
	getdonechunk(stack, chunk, stack->index_a);
	while(stack->index_a > count)
	{	
		j = find_bestforpivot(stack->a, chunk->pivot);
		if(j < 0)
			while(j < 0)
			{
				j++;
				rotate(stack, 'a');
			}
		else
			while(j > 0)
			{
				j++;
				revrotate(stack, 'a');
			}
		ft_print_list(stack);
		push_b(stack);
		i++;
	}
}

void longshort(t_stack *stack)
{
	prepareforjump(stack);
	//if(isshortstack(stack->a) == -1)
		//longshort(stack, chunk);
}



