/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:26:19 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/06 15:45:04 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	rotate(t_stack *stack, int c)
{
	int		i;
	int		aux;

	aux = -1;
	if (c == 'a' && stack->index_a > 1)
	{
		printf("ra\n");
		i = stack->a[0];
		while (++aux < (int)stack->index_a)
			stack->a[aux] = stack->a[aux + 1];
		stack->a[aux - 1] = i;
	}
	else if (c == 'b' && stack->index_b > 1)
	{
		printf("rb\n");
		i = stack->b[0];
		while (++aux < (int)stack->index_b)
			stack->b[aux] = stack->b[aux + 1];
		stack->b[aux - 1] = i;
	}
}

void	rrotate(t_stack *stack)
{
	int		i;
	size_t	aux;

	if (stack->index_a > 1 && stack->index_b > 1)
	{
		printf("rr\n");
		aux = 0;
		i = stack->a[0];
		while (aux < stack->index_a)
		{
			stack->a[aux] = stack->a[aux + 1];
			aux++;
		}
		stack->a[aux - 1] = i;
		aux = 0;
		i = stack->b[0];
		while (aux < stack->index_b)
		{
			stack->b[aux] = stack->b[aux + 1];
			aux++;
		}
		stack->b[aux - 1] = i;
	}
}

int	find_best(int *a, int c, size_t l)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (a[j] != c)
		j++;
	if (j >= (l / 2))
		return (-1);
	else
		return(1);
}
