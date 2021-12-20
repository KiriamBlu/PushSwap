CC		= gcc -Wall -Wextra -Werror
LIB1	= ar -rcs
RM		= /bin/rm -f

NAME	= libft.a

INCLUDE	= .
SRCS	=   ft_strlen.c \
			ft_strnstr.c \
			ft_memset.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_memcpy.c  \
			ft_strchr.c \
			ft_strncmp.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_split.c\

OBJS	= $(SRCS:.c=.o)


all:		$(NAME) bonus

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)

.c.o:
			$(CC) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
