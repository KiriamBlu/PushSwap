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
int		ft_not_short(int argc, char	const **argv);
int		ft_get_no_dup(int argc, char const **argv, char *aux);
size_t	ft_mount_list(int argc, char const **argv, t_stack *a);
void	ft_print_list(t_stack *a);

#endif