CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = cmds.c main.c sort.c organize.c finds.c utils.c check_error.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS) $(NAME)

re: fclean all