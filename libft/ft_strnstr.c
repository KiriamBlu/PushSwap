/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:37:08 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/15 04:39:59 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	stack;

	if (*to_find == '\0')
		return ((char *)str);
	stack = ft_strlen((char *)to_find);
	while (*str != '\0' && len-- >= stack)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, stack) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
