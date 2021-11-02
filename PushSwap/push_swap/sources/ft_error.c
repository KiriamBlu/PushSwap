/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:33:12 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/02 12:17:35 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	ft_get_no_dup(t_stack *a)
{
	t_stack *aux;
	size_t count;

	count = 0;
	aux = NULL;
	aux = a;
	while (a->next)
	{
		count = 0;
		aux = a;
		while(aux)
		{
			if (aux->content == a->content)
				count++;
			if (count != 1)
				return (-1);
			aux = aux->next;
		}
		a = a->next;
	}
	return(1);
}
int	ft_not_short(t_stack *a)
{
	while(a->next)
	{
		if (a->content > a->next->content)
			return(1) ;
		a = a->next;
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
