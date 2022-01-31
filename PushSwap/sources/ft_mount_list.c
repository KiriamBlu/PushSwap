/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mount_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:35:36 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/14 19:10:09 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_table(char ***table)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (table[i])
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
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	table = NULL;
}

static size_t	ft_lsnum(char ***ls)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (ls[i])
	{
		j = 0;
		while (ls[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	ft_atoi_special(const char *str, char ***ls, t_stack *stack)
{
	int				i[2];
	unsigned long	nb;

	i[0] = 0;
	i[1] = 0;
	nb = 0;
	while (str[i[0]] == ' ' || str[i[0]] == '\n' || str[i[0]] == '\t' \
			|| str[i[0]] == '\f' || str[i[0]] == '\v' || str[i[0]] == '\r')
		i[0]++;
	if (str[i[0]] == '+' || str[i[0]] == '-')
		if (str[i[0]++] == '-')
			i[1] = 1;
	while (str[i[0]] >= '0' && str[i[0]] <= '9')
		nb = (nb * 10) + (str[i[0]++] - '0');
	if ((nb > 2147483647 && i[1] == 0) || (nb > 2147483648 && i[1] == 1))
	{
		free_table(ls);
		ft_free_list(stack);
		write(1, "Error\n", 6);
		exit (0);
	}
	else if (i[1] != 0)
		return ((int)nb * -1);
	return ((int) nb);
}

static void	mehelper(t_stack *stack, char ***ls)
{
	size_t	aux;

	aux = ft_lsnum(ls);
	stack->a = malloc(sizeof(int) * aux);
	stack->b = malloc(sizeof(int) * aux);
	stack->aux = malloc(sizeof(int) * aux);
	stack->aux_a = ft_calloc(sizeof(int), aux);
	stack->index_a = aux;
}

void	ft_mount_list(int argc, char const **argv, t_stack *stack)
{
	char	***ls;
	int		pos;
	int		i;
	int		j;

	i = -1;
	pos = 0;
	ls = malloc(sizeof(char **) * argc);
	while (i++ < argc - 1)
	{
		argv = argv + 1;
		ls[i] = ft_split((char *)*argv, ' ');
	}
	mehelper(stack, ls);
	j = 0;
	while (ls[pos])
	{
		i = 0;
		while (ls[pos][i])
			stack->a[j++] = ft_atoi_special(ls[pos][i++], ls, stack);
		pos++;
	}
	free_table(ls);
}
