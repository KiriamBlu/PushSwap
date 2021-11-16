#ifndef PS_HEADER_H
# define PS_HEADER_H
# include "../libft/libft.h"
//# include "../list/lists.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/*-------------------------------LISTS-------------------------------------------*/

typedef struct s_stack
{
	int *a;
	int *b;
	int low;
	int max;
	size_t index_a;
	size_t index_b;
} t_stack;

typedef struct s_ch
{
	int *ch;
	int pivot;
	size_t index_ch;
} t_ch;

/*--------------------------NUMERIC CONTROL--------------------------------------*/

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
void	getdonechunk(t_stack *stack, t_ch *chunk, size_t chunksize);
int		getdonechunk_a(t_stack *stack, size_t chunksize);
int 	ft_get_nothing_else_num(int argc ,char const **argv);
int 	ft_check_sign(int argc, const char **str);
int		ft_atoi_special(const char *str, char ***ls);

/*----------------------------Movements------------------------------------------*/

void push_b(t_stack *stack);
void push_a(t_stack *stack);
void swap(t_stack *stack, int c);
void rotate(t_stack *stack, int c);
void rrotate(t_stack *stack);
void revrotate(t_stack *stack, int c);
void rrevrotate(t_stack *stack);

/*---------------------------Algorithms-----------------------------------------*/

void	ft_shorting(t_stack *stack, t_ch *chunk);
void	smallshort(t_stack *stack);
void	twoshort(t_stack *stack, int c);
void	threeshort_a(t_stack *stack);
void	threeshort_b(t_stack *stack);
void	aftershort(t_stack *stack);
int		find_best(int *a, int c, size_t l);
void	fourshort(t_stack *stack);
void	fiveshort(t_stack *stack);
void	ft_algowheel(t_stack *stack, t_ch *chunk);
void	longshort(t_stack *stack, t_ch *chunk);
int		find_bestforpivot(int *a, int c, size_t l);

#endif