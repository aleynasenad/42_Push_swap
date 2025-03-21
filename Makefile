NAME    = push_swap

SRCS    = check_errors.c create_stack.c prep_a_to_push.c prep_b_to_push.c \
          push_swap.c push.c reverse_rotate.c rotate.c start_sorting.c \
          swap.c utils.c sort_three.c create_stack_for_array.c

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(LIBFT_DIR) -g
RM        = rm -f

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	make -s -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
