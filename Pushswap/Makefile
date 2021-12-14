NAME := push_swap
LIBFT_NAME = libft.a

SRCS =  ./sources/push_swap.c \
		./sources/ft_mount_list.c \
		./sources/ft_error.c \
		./sources/ft_error_two.c \
		./sources/ft_push.c \
		./sources/ft_swap.c \
		./sources/ft_rotate.c \
		./sources/ft_revrotate.c \
		./sources/ft_shorting.c \
		./sources/ft_shorting2.c \
		./sources/ft_shorting3.c \
		./sources/ft_algowheel.c \
		./sources/ft_shortingforlong.c \
		./sources/ft_getargsready.c \
		./sources/ft_shorting4.c \
		./sources/ft_bigslowshort.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./header/
EXE_DIR = ./

CC := cc
GCC := gcc -g
CFLAGS := -Wall -Wextra -Werror  
MV := mv -f
RM := rm -f

%.o: %.c
	$(GCC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(GCC) -o $(NAME)  $^ -I $(INC_DIR)

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

