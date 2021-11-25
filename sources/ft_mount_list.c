/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mount_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:35:36 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/11/25 11:08:00 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_table(char ***table)
{
	int	pos;
	int i;

	pos = 0;
	i = 0;
	while(table[i])
	{
		pos = 0;
		while (table[i][pos])
		{
			free(table[i][pos]);
			pos++;
		}
		i++;
	}
	i = 0;
	while(table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	table = NULL;
}

static size_t ft_lsnum(char ***ls)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	j = 0;
	count = 0;
	while(ls[i])
	{
		j = 0;
		while(ls[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return(count);
}

int	ft_atoi_special(const char *str, char ***ls)
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
		free_table(ls);
		write(1, "Error\n", 6);
		exit (0);
	}
	else if (sign != 0)
		return ((int)nb * -1);
	return ((int) nb);
}

void ft_mount_list(int argc, char const **argv, t_stack *stack) //REDUCIR UNA LINEA EL CODIGO
{
	char	***ls;
	int		pos;
	size_t	aux;
	int		i;
	int		j;

	i = -1;
	pos = 0;
	aux = 0;
	ls = malloc(sizeof(char **) * argc);
	while (i++ < argc - 1)
	{
		argv = argv + 1;
		ls[i] = ft_split((char *)*argv, ' ');
	}
	aux = ft_lsnum(ls);
	stack->a = malloc(sizeof(int) * aux);
	stack->b = malloc(sizeof(int) * aux);
	stack->aux = malloc(sizeof(int) * aux);
	stack->aux_a = ft_calloc(sizeof(int), aux);
	stack->index_a = aux;
	j = 0;
	while(ls[pos])
	{
		i = 0;
		while(ls[pos][i])
			stack->a[j++]  = ft_atoi_special(ls[pos][i++], ls);
		pos++;
	}
	free_table(ls);
	return ;
}

