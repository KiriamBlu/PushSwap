NAME := push_swap
LIBFT_NAME = libft.a

SRCS =  ./sources/push_swap.c \
		./sources/ft_mount_list.c \
		./sources/ft_error.c \
		./sources/ft_error_two.c \
		./sources/ft_printing_shit.c \
		./sources/ft_push.c \
		./sources/ft_swap.c \
		./sources/ft_rotate.c \
		./sources/ft_revrotate.c \
		./sources/ft_shorting.c \
		./sources/ft_shorting2.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./header/
EXE_DIR = ./

CC := cc
GCC := gcc
CFLAGS := -Wall -Werror -Wextra 
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^ -I $(INC_DIR)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
