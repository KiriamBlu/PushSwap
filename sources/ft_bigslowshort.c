/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigslowshort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:13:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/02 13:21:36 by jsanfeli         ###   ########.fr       */
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
	static int	s;
	int			pivot;
	int			num[2];
	size_t		z[2];
	size_t		*a;

	z[0] = 0;
	z[1] = (stack->index_a / 3 + 10);
	pivot = getpositionpivot(stack->index_a, stack->a);
	while (z[0] <= z[1] && numlowerpiv(stack->a, pivot, stack->index_a) == 1
		&& stack->index_a != 3)
	{
		if ((stack->index_b) == 3)
			s = find_bestforpivot(stack->a, pivot, stack->index_a);
		a = getpositions(stack, pivot, s, a);
		num[0] = stack->a[a[0]];
		num[1] = stack->b[a[1]];
		dodoble(stack, a[0], a[1]);
		free(a);
		ft_prepa(stack, num[0]);
		ft_algowheel(stack, num[1]);
		z[0]++;
	}
	if (stack->index_a != 3)
		recursiveshortforlong(stack);
}
