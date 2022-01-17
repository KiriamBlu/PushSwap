/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigslowshort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:13:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/14 16:35:50 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

size_t	getb(t_stack *stack, int numa, size_t	count)
{
	int		*temp;
	size_t	i;

	temp = NULL;
	if (stack->index_b > 3 && count == 0)
	{
		i = 0;
		temp = getdonechunkforaux(stack->aux, stack->index_b, stack->b[0]);
		while (i < stack->index_b)
		{
			if (temp[i] != stack->aux[i])
				stack->aux[i] = temp[i];
			i++;
		}
		free(temp);
	}
	i = 0;
	while (numa < stack->aux[i] && i < stack->index_b)
		i++;
	return (i);
}

int	geta(t_stack *stack, int pivot, size_t	pru, int s)
{
	size_t	position;

	position = 0;
	if (stack->index_a != 1)
		position = getlowerpivotforlong(stack, pivot, s, pru);
	else
		position = 0;
	return (position);
}

static size_t	*resetaux(size_t *l, t_stack *stack)
{	
	size_t	m;

	m = 0;
	l[0] = l[0] + 1;
	l[1] = 0;
	while (stack->aux_a[m])
	{
		stack->aux_a[m] = 0;
		m++;
	}
	return (l);
}

static size_t	*getpositions(t_stack *stack, int pivot, int s, size_t *a)
{
	size_t	i;
	size_t	*l;
	size_t	position;

	l = ft_calloc(sizeof(size_t), 2);
	a = malloc(sizeof(size_t) * 2);
	while (l[1] < stack->index_a - 1)
	{
		position = geta(stack, pivot, l[1], s);
		if (position > 2147483647)
			break ;
		stack->aux_a[l[1]] = stack->a[position];
		a[0] = position;
		i = getb(stack, stack->a[position], l[1]);
		a[1] = findereal(stack->aux[i], stack->b, stack->index_b);
		if (a[1] < ((stack->index_b / 2 - (stack->index_b / 3) - l[0]) - 1)
			|| a[1] > ((stack->index_b / 2 + (stack->index_b / 3) + l[0]) - 1))
			break ;
		if (l[1] == l[0])
			l = resetaux(l, stack);
		l[1]++;
	}
	free(l);
	return (a);
}

void	recursiveshortforlong(t_stack *stack)
{
	int *chunk;
	size_t chunksize;
	size_t k;
	size_t *a;
	int		i;
	int		num[2];

	chunksize = -1;
	chunk = getdonechunk(stack->a, stack->index_a, -1);
	chunksize = 20;
	while(stack->index_a != 0)
	{
		i = find_bestforpivot(stack->a, chunk[chunksize - 1], stack->index_a);
		while(stack->index_b <= chunksize)
		{
			printf("KK\n");
			if(stack->index_b >= 1 && stack->index_a > 20)
			{
				a = getpositions(stack, chunk[chunksize - 1], i, a);
				num[0] = stack->a[a[0]];
				num[1] = stack->b[a[1]];
				printf("%d\n", num[0]);
				printf("%d\n", num[1]);
				sleep(10);
				dodoble(stack, a[0], a[1]);
				free(a);
			}
			else
				num[0] = stack->a[getlowerpivot(stack->a, chunk[chunksize - 1], stack->index_a, i)];
			ft_prepa(stack, num[0]);
			push_a(stack);
			printf("LOKO");
			k = -1;
			while (++k < stack->index_b)
			printf("%d_____________", stack->b[k]);
		}
		chunksize = chunksize + 20;
	}
	return ;
}
