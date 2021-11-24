/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargsready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:43:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/24 09:58:25 by jsanfeli         ###   ########.fr       */
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