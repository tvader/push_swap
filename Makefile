NAME = push_swap

CH_NAME = checker

PS_SRCS =  srcs_push_swap/main.c srcs_push_swap/operations_r.c \
srcs_push_swap/operations_sp.c srcs_push_swap/operations_rr.c \
srcs_push_swap/stack_creation.c srcs_push_swap/stack_info1.c \
srcs_push_swap/stack_info2.c  \
srcs_push_swap/clear.c srcs_push_swap/stack_edit.c \
srcs_push_swap/utils.c srcs_push_swap/sort_junior.c

CH_SRCS = srcs_checker/ch_main.c srcs_checker/ch_clear.c \
srcs_checker/ch_operations_r.c srcs_checker/ch_operations_rr.c \
srcs_checker/ch_operations_sp.c srcs_checker/ch_stack_creation.c \
srcs_checker/ch_stack_info.c srcs_checker/ch_utils.c

CC = gcc -Wall -Wextra -Werror

INCLUDES = -I.

PS_OBJS = $(PS_SRCS:.c=.o)

CH_OBJS = $(CH_SRCS:.c=.o)

$(NAME): $(PS_OBJS)
	$(MAKE) -C ./libft --silent
	$(CC) -o $(NAME) $(PS_OBJS) -L./libft -lft

$(CH_NAME): $(CH_OBJS)
	$(MAKE) -C ./libft --silent
	$(CC) -o $(CH_NAME) $(CH_OBJS) -L./libft -lft

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft --silent
	rm -rf $(PS_OBJS)
	rm -rf $(CH_OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft --silent
	rm -rf $(NAME)
	rm -rf $(CH_NAME)

bonus : $(CH_NAME)

re : fclean all

rebonus: fclean bonus
