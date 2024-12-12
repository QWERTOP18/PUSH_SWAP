NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs
INCL_DIR = ./includes

SRCS = $(SRCS_DIR)/ft_printf.c \
       $(SRCS_DIR)/print_char.c \
	   $(SRCS_DIR)/print_nbr.c \
	   $(SRCS_DIR)/print_hex.c \
	   $(SRCS_DIR)/print_addr.c \
	   $(SRCS_DIR)/print_str.c \
	   $(SRCS_DIR)/print_unsigned.c \
       $(SRCS_DIR)/utils.c \
	   $(INCL_DIR)/func1.c \
	   $(INCL_DIR)/func2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created!"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCL_DIR) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJS)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
