NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		ft_strchr.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcpy.c ft_atoi.c \
		ft_memset.c ft_memcpy.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memmove.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c ft_itoa.c \

BONUSSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c \
		ft_lstiter_bonus.c
		

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS = $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_funcs1.c $(FT_PRINTF_DIR)/ft_funcs2.c
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	ar -rc $(NAME) $(OBJS) $(FT_PRINTF_OBJS)

bonus: $(BONUSOBJS)
	ar -rc $(NAME) $(BONUSOBJS)

clean:
	$(RM) $(OBJS) $(BONUSOBJS) $(FT_PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
