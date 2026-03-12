NAME = tetris_game
SRCSDIR = srcs
SRCS =	main.c \
	$(SRCSDIR)/pieces_def.c  \
	$(SRCSDIR)/pieces_game.c  \
	$(SRCSDIR)/pieces_mov.c  \
	$(SRCSDIR)/grid.c  \
	$(SRCSDIR)/lines.c  \
	$(SRCSDIR)/collision.c  \
	$(SRCSDIR)/term_cntl.c  \
	$(SRCSDIR)/exits.c
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
