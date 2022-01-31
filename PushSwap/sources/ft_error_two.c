/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:12:57 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/01/31 18:32:31 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

static int	ft_is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (-1);
}

int	ft_check_sign(int argc, const char **str)
{
	char	**aux;
	int		i;
	int		count;
	int		k;

	k = 0;
	count = 0;
	aux = (char **)str;
	while (count < argc)
	{
		i = 0;
		while (aux[count][i])
		{
			k = (int)aux[count][i];
			if (k == 43 && (ft_is_digit((int)aux[count][i + 1]) == -1) |
				(ft_is_digit((int)aux[count][i - 1]) == 1 && k == 43))
				return (-1);
			if (k == 45 && (ft_is_digit((int)aux[count][i + 1]) == -1) |
				(ft_is_digit((int)aux[count][i - 1]) == 1 && k == 45))
				return (-1);
			i++;
		}
		count++;
	}
	return (1);
}

void	checkls(char ***ls, int i)
{
	if (!ls[i])
	{
		free_table(ls);
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	ft_get_numlow(t_stack *stack)
{
	t_stack	*aux;
	size_t	check;
	size_t	count;
	size_t	tmp;

	count = 0;
	aux = NULL;
	aux = stack;
	while (count < stack->index_a)
	{
		tmp = 0;
		aux = stack;
		check = 0;
		while (tmp < stack->index_a)
		{
			if (stack->a[count] <= aux->a[tmp])
				check++;
			if (check == stack->index_a)
				stack->low = stack->a[count];
			tmp++;
		}
		count++;
	}
	return ;
}
