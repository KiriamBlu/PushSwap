/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:33:12 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/10/29 14:51:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	ft_get_no_dup(char const **ls, char *aux)
{
	size_t count;
	char	**tmp;

	tmp = (char **)ls;
	count = 0;
	while (tmp)
	{
		if(ft_strcmp((const char *)*tmp, (const char *)aux) == -1)
			return(-1);
		*tmp = *tmp + 1;
	}
	return(1);
}
int	ft_not_short(t_stack *a)
{
	while(a->content < a->next->content)
	{
		if (a->content > a->next->content)
			return(1) ;
	}
	return(-1);	
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] == s2[cont])
	{
		if (s1[cont] != s2[0])
			return(1);
		cont++;
	}
	return (-1);
}
