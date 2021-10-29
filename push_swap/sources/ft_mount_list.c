#include "ps_header.h"


t_stack *ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return(lst);
}

void ft_lstadd_back(t_stack *lst, t_stack *new)
{
	if (lst->index == 0)
	{
		lst->content = new->content;
		lst->index++;
		return ;
	}
	else
	{
		(ft_lstlast(lst))->next = new;
	}
}

t_stack *ft_lstnew(int content)
{
	t_stack *l;
	l = malloc(sizeof(t_stack));
	if(!l)
		return(NULL);
	l->content = content;
	l->next = 0;
	return(l);
}

size_t ft_mount_list(int argc, char const **argv, t_stack *a)
{
	char	**ls;
	int		i;
	size_t	j;
	size_t	k;

	i = 1;
	j = 0;
	while (i < argc)
	{
		argv = argv + 1;
		ls = ft_split((char *)*argv, ' ');
		k = 0;
		while(ls[k])
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(ls[k++])));
			j++;
		}
		free(ls);
		i++;
	}
	return (j);
}

void ft_print_list(t_stack *a)
{
	while(a)
	{
		printf("[%d]\n", a->content);
		a = a->next;
	}
}






