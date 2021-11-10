/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:14:06 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/09/22 13:54:52 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	len;

	a = 0;
	while (*(dst + a) != '\0')
		a++;
	if (a >= size)
		return (size + ft_strlen(src));
	len = a;
	b = 0;
	while (src[b] && a < size - 1)
	{
		dst[a] = src[b];
		b++;
		a++;
	}
	dst[a] = '\0';
	return (ft_strlen(src) + len);
}
