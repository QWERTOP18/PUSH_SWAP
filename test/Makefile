CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCDIR = .
LIBFTDIR = ../libft

SRCS = \
	$(SRCDIR)/list_heapq.c \
	$(SRCDIR)/push.c \
	$(SRCDIR)/rotate.c \
	$(SRCDIR)/util_math.c \
	$(SRCDIR)/list_utils.c \
	$(SRCDIR)/reverse_rotate.c \
	$(SRCDIR)/swap.c

LIBFT = $(LIBFTDIR)/libft.a

OBJS = $(SRCS:.c=.o)

NAME = libclst.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)
	ranlib $(NAME)

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
