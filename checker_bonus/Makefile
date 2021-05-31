CFLAGS = -Wall -Werror -Wextra

NAME = checker

SRCS = checker.c get_next_line.c get_next_line_utils.c ../mandatory/finds.c ../mandatory/cmds.c ../mandatory/cmds2.c ../mandatory/check_error.c ../mandatory/utils.c ../mandatory/utils2.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS) $(NAME)

re: fclean all