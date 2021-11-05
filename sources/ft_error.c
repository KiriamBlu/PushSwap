/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:33:12 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/05 11:39:35 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	ft_get_no_dup(t_stack *stack)
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
			if (aux->a[tmp] == stack->a[count])
				check++;
			if (check > 1)
				return (-1);
			tmp++;
		}
		count++;
	}
	return(1);
}

int	ft_not_short(t_stack *stack)
{
	size_t tmp;
	size_t aux;

	tmp	= 0;
	aux = stack->index_a;
	aux = aux - 1;
	while(tmp < aux)
	{
		if (stack->a[tmp] > stack->a[tmp + 1])
			return(1) ;
		tmp++;
	}
	return(-1);	
}

int	ft_strcmp(char *s1, char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] && s2[cont])
	{
		if (s1[cont] != s2[cont])
			return(1);
		cont++;
	}
	return (-1);
}

int ft_get_nothing_else_num(int argc ,char const **argv)
{
	int i;
	int k;
	char **aux;

	i = 1;
	aux = (char **)argv;
	while(i < argc)
	{
		k = 0;
		while(aux[i][k])
		{
			if (ft_isnum(aux[i][k++]) != 1)
				return(-1);
		}
		i++;
	}
	return(1);
}


int	ft_isnum(int c)
{
	if ((c >= 48 && c <= 57) || c == 45 || c == 43 || c == ' ')
	{
		return (1);
	}
	return (-1);
}
