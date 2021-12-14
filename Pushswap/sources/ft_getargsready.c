/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargsready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:43:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/06 17:08:55 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	numlowerpiv(int *a, int pivot, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		if (a[i] <= pivot)
			return (1);
		i++;
	}
	return (0);
}
