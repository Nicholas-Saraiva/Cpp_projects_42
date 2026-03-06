SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)
NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re