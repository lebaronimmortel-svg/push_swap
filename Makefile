SRC = create_lst.c link.c\
      main_utils.c list_utils.c swap.c\
      main.c push.c rotate.c new_tail.c\
      reverse_rotate.c sort.c sort_utils.c utils.c\
      find_next_close.c sort_small.c
     
OBJS = $(SRC:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) -f $(OBJS) 

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
