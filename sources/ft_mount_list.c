/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mount_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:35:36 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/04 17:30:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_table(char **table)
{
	int	pos;

	pos = 0;
	while (table[pos])
	{
		free(table[pos]);
		pos++;
	}
	free(table);
	table = NULL;
}

void ft_mount_list(int argc, char const **argv, t_stack *stack)
{
	char	**ls;
	int		pos;
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	stack->a = malloc(sizeof(t_stack));
	stack->b = malloc(sizeof(t_stack));
	if(!stack->a || !stack->b || ft_check_sign(argc, argv) == -1)
	{
		ft_error_message(stack);
	}
	while (i++ < argc)
	{
		argv = argv + 1;
		ls = ft_split((char *)*argv, ' ');
		pos = 0;
		while(ls[pos])
			stack->a[j++]  = ft_atoi_special(ls[pos++], ls, stack);
		free_table(ls);
	}
	stack->index_a = j;
	return ;
}

int	ft_atoi_special(const char *str, char **ls, t_stack *stack)
{
	int				i;
	int				sign;
	unsigned long	nb;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');	
	if ((nb > 2147483647 && sign == 0) || (nb > 2147483648 && sign >= 1))
	{
		free(ls);
		ft_error_message(stack);
	}
	else if (sign != 0)
		return ((int)nb * -1);
	return ((int) nb);
}






