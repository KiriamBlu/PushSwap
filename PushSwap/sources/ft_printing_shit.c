/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/05 11:39:30 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void ft_print_list(t_stack *stack)
{
	size_t aux;

	aux = 0;
	printf("*****************LISTA A\n");
	while(aux < stack->index_a)
	{
		printf("*Posición: %zu ----[%d]\n", aux ,stack->a[aux]);
		aux++;
	}
	printf("*****************LISTA B\n");
	aux = 0;
	while(aux < stack->index_b)
	{
		printf("*Posición: %zu ----[%d]\n", aux ,stack->b[aux]);
		aux++;
	}
	printf("*************************\n\n\n");
}