/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigslowshort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:13:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/28 15:07:55 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"


static int	decidemiddle(int m, int s)
{
	if (m < 0 && s != 0)
		return (-1);
	else if (m >= 0 && s != 0)
		return (1);
	else
		return(0);
}

int	find_bestforchunk(int *a, int ntwo, int none, size_t l)
{
	int				m;
	unsigned long	j;
	int				s;

	j = 0;
	s = 0;
	m = 0;
	while (a[j])
	{
		if ((a[j] <= ntwo) && (a[j] >= none) && j < (l / 2))
		{
			s++;
			m++;
		}
		else if ((a[j] <= ntwo) && (a[j] >= none && j) >= (l / 2))
		{
			s++;
			m--;
		}
		j++;
	}
	return (decidemiddle(m, s));
}


size_t	getlowerchunk(t_stack *stack, int ntwo, int none, int l)
{
	size_t	i;

	i = 0;
	if(l == -1)
	{
		while (i < stack->index_a)
		{
			if (stack->a[i] <= ntwo && stack->a[i] >= none)
				return (i);
			i++;
		}
	}
	else
	{
		i = stack->index_a - 1;
		while(i > 0)
		{
			if (stack->a[i] <= ntwo && stack->a[i] >= none)
				return (i);
			i--;
		}
	}
	return (-404);
}

static void reset(t_stack *stack, int big)
{
	size_t i;

	i = 0;
	while(stack->a[i] != big)
		i++;
	if (i > (stack->index_a/2))
		while(stack->a[stack->index_a - 1] != big)
			revrotate(stack, 'a');
	else
		while(stack->a[stack->index_a - 1] != big)
			rotate(stack, 'a');
}

static void makechunk(size_t c0, size_t c1, t_stack *stack, int *chunk)
{
	int		i;
	int		num;

	while(stack->index_b < 20)
	{
		i = find_bestforchunk(stack->a, chunk[c0], chunk[c1], stack->index_a);
		num = stack->a[getlowerchunk(stack, chunk[c0], chunk[c1], i)];
		ft_prepa(stack, num);
		push_b(stack);
	}
	if(c0 != 0)
		reset(stack, chunk[0]);
	finalpart(stack, chunk[c1]);
}

void	recursiveshortforlong(t_stack *stack)
{
	int *chunk;
	size_t chunksize[2];
	size_t max_num;

	chunksize[0] = 0;
	chunksize[1] = 19;
	chunk = getdonechunk(stack->a, stack->index_a, 1);
	max_num = stack->index_a;
	while(chunksize[1] != max_num)
	{
		makechunk(chunksize[0], chunksize[1], stack, chunk);
		chunksize[0] = chunksize[0] + 20;
		chunksize[1] = chunksize[1] + 20;
		if (chunksize[1] > max_num)
			chunksize[1] = max_num;
	}
	reset(stack, chunk[0]);
	free(chunk);
}

static int	get_numlow(t_stack *stack)
{
	t_stack	*aux;
	size_t	check;
	size_t	count;
	size_t	tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_b)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while (tmp < stack->index_b)
		{
			if (stack->b[count] <= aux->b[tmp])
				check++;
			if (check == stack->index_b)
				return(stack->b[count]);
			tmp++;
		}
		count++;
	}
	return (0);
}

static int	get_nummax(t_stack *stack)
{
	t_stack	*aux;
	size_t	check;
	size_t	count;
	size_t	tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_b)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while (tmp < stack->index_b)
		{
			if (stack->b[count] >= aux->b[tmp])
				check++;
			if (check == stack->index_b)
				return(stack->b[count]);
			tmp++;
		}
		count++;
	}
	return (0);
}

static void fight(int i, size_t max, size_t min, t_stack *stack)
{
	if (i == 1)
	{
		if (min > stack->index_b / 2)
			while(stack->b[0] != get_numlow(stack))
				revrotate(stack, 'b');
		else
			while(stack->b[0] != get_numlow(stack))
				rotate(stack, 'b');
	}
	else
	{
		if (max > stack->index_b / 2)
			while(stack->b[0] != get_nummax(stack))
				revrotate(stack, 'b');
		else
			while(stack->b[0] != get_nummax(stack))
				rotate(stack, 'b');
	}
}

static void chooseyourfighter(t_stack *stack)
{
	size_t		i;
	size_t		max;
	size_t		min;

	i = 0;
	while(i < stack->index_b)
	{
		if(stack->b[i] == get_nummax(stack))
			max = i;
		if(stack->b[i] == get_numlow(stack))
			min = i;
		i++;
	}
	i = 0;
	if((min > stack->index_b/2 && max < min) 
		|| (min < stack->index_b/2 && max > min))
		i = 1;
	fight(i, max, min, stack);
}

void finalpart(t_stack *stack, int big)
{	
	size_t		i;

	i = 0;
	while(stack->index_b > 0)
	{
		chooseyourfighter(stack);
		if (stack->b[0] > stack->a[0])
		{
			rotate(stack, 'a');
			push_a(stack);
		}
		else
			push_a(stack);
	}
	while(stack->a[0] != big)
		rotate(stack, 'a');
	rotate(stack, 'a');
}
/*
size_t m = -1;
while(++m < stack->index_a)
	printf("%zu: %d\n", m, stack->a[m]);
*/