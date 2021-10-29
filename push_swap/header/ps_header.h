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
	int content;
	size_t index;
	struct s_stack *next;
} t_stack;


/*--------------------------NUMERIC CONTROL--------------------------------------*/

int		ft_error(int argc, char const **argv);
int		ft_not_short(t_stack *a);
int		ft_get_no_dup(char const **ls, char *aux);
size_t	ft_args_managment(int argc, char const **argv, t_stack *a);
size_t	ft_mount_list(int argc, char const **argv, t_stack *a);
void	ft_print_list(t_stack *a);
void	ft_free_list(t_stack *stack);
void	ft_error_message(void);
int		ft_strcmp(const char *s1, const char *s2);


#endif