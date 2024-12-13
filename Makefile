CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes


SRCDIR = ./srcs
UTILSDIR = ./utils/list_funcs
LIBFTDIR = ./utils/libft

SRCS = \
	$(SRCDIR)/a1_main.c \
	$(SRCDIR)/a2_parse.c \
	$(SRCDIR)/b1_handler.c \
	$(SRCDIR)/b2_calculate.c \
	$(SRCDIR)/b3_buildfuncs.c \

CLST = $(CLSTDIR)/libclst.a

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(CLST) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLST) -o $@

$(CLST):
	make -C $(UTILSDIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
