/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortingforlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:29 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/11 10:42:19 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int decidemiddle(int m)
{
	if(m < 0)
		return(-1);
	else
		return(1);
}

int find_bestforpivot(int *a, int c, size_t l)
{
	int m;
	unsigned long j;
	
	j = 0;
	m = 0;
	while(a[j])
	{
		if((l % 2) == 0)
		{
			if(a[j] <= c && j < (l/2))
				m++;
			else if(a[j] <= c && j > (l/2))
				m--;
		}
		else
		{
			if(a[j] < c && j < (l/2))
				m++;
			else if(a[j] < c && j > (l/2))
				m--;
		}
		j++;
	}
	return(decidemiddle(m));
}
