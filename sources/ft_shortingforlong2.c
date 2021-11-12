/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortingforlong2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:59:28 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:15:07 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int calculatemoves(int *a, int c);

int	ft_get_numlow(int *a, size_t l)
{
	int *b;
	size_t count;
	size_t tmp;

	count = 0;
	while (a[count])
	{
		tmp = 0;
		b = a;
		while(a[count] <= b[tmp])
		{
			tmp++;
			if(tmp == l)
				return(a[count]);
		}	
		count++;
	}
	return(0);
}

int	ft_get_numhigh(int *a, size_t l)
{
	int *b;
	size_t count;
	size_t tmp;

	count = 0;
	while (a[count])
	{
		tmp = 0;
		b = a;
		while(a[count] >= b[tmp])
		{
			tmp++;
			if(tmp == l)
				return(a[count]);
		}	
		count++;
	}
	return(0);
}

static void dolastrotate(t_stack *stack, int high, int low)
{
	int moves;

	moves = 0;
	if (stack->a[0] != low)
	{
		moves = calculatemoves(stack->a, low);
		if (moves < 0)
			while(stack->a[0] != low)
				rotate(stack, 'a');
		else
			while(stack->a[0] != low)
				revrotate(stack, 'a');
	}
	if(stack->b[0] != high)
	{
		moves = calculatemoves(stack->b, high);
		if (moves < 0)
			while(stack->b[0] != high)
				rotate(stack, 'b');
		else
			while(stack->b[0] != high)
				revrotate(stack, 'b');
	}
}

static void getrotated(int high, int low, t_stack *stack)
{
	int last;
	int i;

	i = 0;
	if(low > high)
		last = low - high;
	else
		last = high - low;
	if(low > high && low > 0 && high > 0) //AQUI SE PUEDE REDUCIR CALCULANDO SI LOS RRR LES VALE MAS LA PENA AUN QUE NO SEA EL CAMINO OPTMO
		while(i++ < last)
			rrotate(stack);
	else if(low < high && low > 0 && high > 0)
		while(i++ < last)
			rrotate(stack);
	else if(low > high && low < 0 && high < 0)
		while(i++ < last)
			rrevrotate(stack);
	else if(low < high && low < 0 && high < 0)
		while(i++ < last)
			rrevrotate(stack);
}


static void get_rotate(t_stack *stack)
{
	int low;
	int high;
	int pa;
	int pb;
	
	low = ft_get_numlow(stack->a, stack->index_a);
	high = ft_get_numhigh(stack->b, stack->index_b);
	if(stack->a[0] != low && stack->b[0] != high)
	{
		pa = calculatemoves(stack->a, low);
		pb = calculatemoves(stack->a, high);
		getrotated(pb, pa, stack);
	}
	dolastrotate(stack, high, low);
}


void prepareforjump(t_stack *stack)
{
	get_rotate(stack);
}

int calculatemoves(int *a, int c)
{
	int k;
	int u;
	int j;
	
	j = 0;
	k = 0;
	u = 0;
	while(a[k])
		k++;
	while(a[j] != c)
		j++;
	while(a[k] != c)
	{
		u++;
		k--;
	}
	return(decidemiddle(j, u, -1));
}



