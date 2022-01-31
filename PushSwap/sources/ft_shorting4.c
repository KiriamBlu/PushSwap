/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:35:37 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/31 19:15:14 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	longshort(t_stack *stack)
{
	if (stack->index_a < 20)
		recursiveshortforlong(stack, 1);
	else if (stack->index_a < 250)
		recursiveshortforlong(stack, 15);
	else
		recursiveshortforlong(stack, 40);
}
