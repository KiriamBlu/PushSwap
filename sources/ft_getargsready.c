/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargsready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:43:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:23 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int therearenumberlowerpivot(int *a, int pivot, size_t l)
{
	size_t i;

	i = 0;
	while(i < l)
	{
		if(a[i] <= pivot)
			return(1);
		i++;
	}
	return(0);
}

static void rotatefunc(size_t rotate, t_stack *stack)
{
	while(rotate != 0)
		{
			rrotate(stack);
			rotate--;
		}
}

static void revrotatefunc(size_t rotate, t_stack *stack)
{
	while(rotate != 0)
		{
			rrevrotate(stack);
			rotate--;
		}
}

void ft_getargsready(size_t pos_a, size_t pos_b ,t_stack *stack)
{
	size_t a_rot;
	size_t a_revrot;
	size_t b_rot;
	size_t b_revrot;

	a_rot = 0;
	a_revrot = 0;
	b_revrot = 0;
	b_rot = 0;
	if(pos_a < ((stack->index_a / 2) - 1))
		a_rot =  pos_a;
	else
		a_revrot = pos_a;
	if(pos_b < ((stack->index_a / 2) - 1))
		b_revrot =  pos_b;
	else
		b_rot = pos_b;
	if (a_rot > b_rot && b_rot != 0)
		rotatefunc(b_rot, stack);
	if (a_rot < b_rot && a_rot != 0)
		rotatefunc(a_rot, stack);
	if (a_revrot < b_revrot && a_revrot != 0)
		revrotatefunc(a_revrot, stack);
	if (a_revrot > b_revrot && b_revrot != 0)
		revrotatefunc(b_revrot, stack);
}