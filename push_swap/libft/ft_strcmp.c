/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:06:15 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/09/22 13:56:28 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] == s2[cont])
		if (s1[cont] != s2[cont])
			return(1);
		cont++;
	return (-1);
}