#ifndef LISTS_H
# define LISTS_H

--------------------------------------LISTS------------------------------------

typedef struct s_list
{
	int content;
	int index;
	struct s_list *next;
} t_list;

#endif