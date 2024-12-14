CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
INCLUDES = -I./includes

SRCDIR = ./srcs
UTILSDIR = $(SRCDIR)/list_funcs
LIBFTDIR = ./utils/libft

SRCS = \
	$(SRCDIR)/a1_main.c \
	$(SRCDIR)/a2_parse.c \
	$(SRCDIR)/b1_handler.c \
	$(SRCDIR)/b2_calculate.c \
	$(SRCDIR)/b3_buildfuncs.c \
	$(UTILSDIR)/list_heapq.c \
	$(UTILSDIR)/push.c \
	$(UTILSDIR)/rotate.c \
	$(UTILSDIR)/util_math.c \
	$(UTILSDIR)/list_utils.c \
	$(UTILSDIR)/reverse_rotate.c \
	$(UTILSDIR)/swap.c

LIBFT = $(LIBFTDIR)/libft.a

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
