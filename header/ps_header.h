/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:30:15 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/02 12:45:31 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H
# include "../libft/libft.h"
//# include "../list/lists.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/*-------------------------------LISTS---------------------------------------*/

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		*aux_a;
	int		*aux;
	int		low;
	int		max;
	size_t	index_a;
	size_t	index_b;
}	t_stack;

/*--------------------------NUMERIC CONTROL----------------------------------*/

int		ft_error(int argc, char const **argv);
int		ft_not_short(t_stack *a);
int		ft_get_no_dup(t_stack *a);
void	ft_args_managment(int argc, char const **argv, t_stack *a);
void	ft_mount_list(int argc, char const **argv, t_stack *stack);
void	ft_print_list(t_stack *a);
void	ft_free_list(t_stack *stack);
void	ft_error_message(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		ft_isnum(int c);
void	ft_get_numlow(t_stack *stack);
void	ft_get_nummax(t_stack *stack);
int		*getdonechunk(int *stack, size_t chunksize, int sign);
int		getpositionpivot(size_t chunksize, int *stack);
int		ft_get_nothing_else_num(int argc, char const **argv);
int		ft_check_sign(int argc, const char **str);

/*----------------------------Movements--------------------------------------*/

void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	swap(t_stack *stack, int c);
void	rotate(t_stack *stack, int c);
void	rrotate(t_stack *stack);
void	revrotate(t_stack *stack, int c);
void	rrevrotate(t_stack *stack);

/*---------------------------Algorithms--------------------------------------*/

void	ft_shorting(t_stack *stack);
void	smallshort(t_stack *stack);
void	twoshort(t_stack *stack, int c);
void	threeshort_a(t_stack *stack);
void	threeshort_b(t_stack *stack);
void	aftershort(t_stack *stack);
int		find_best(int *a, int c, size_t l);
void	fourshort(t_stack *stack);
void	fiveshort(t_stack *stack);
void	ft_algowheel(t_stack *stack, int k);
void	longshort(t_stack *stack);
void	longlongshort(t_stack *stack);
int		find_bestforpivot(int *a, int c, size_t l);
int		numlowerpiv(int *a, int pivot, size_t l);
void	ft_getargsready(size_t pos_a, size_t pos_b, t_stack *stack);
void	ft_prepa(t_stack *stack, int position);
void	recursiveshort(t_stack *stack);
void	recursiveshortforlong(t_stack *stack);
int		*getdonechunkforaux(int *stack, size_t chunksize, int new_b);
size_t	findereal(int aux, int *stack, size_t index);
void	dodoble(t_stack *stack, size_t position, size_t aux);
size_t	getlowerpivotforlong(t_stack *stack, int pivot, int m, size_t pru);

#endif