#//---Files--//#
NAME = fight
SRC_DIR = .
BUILD_PATH  = .build/
INC_DIR = .

FILES = main
FILES += Weapon
FILES += HumanA
FILES += HumanB

OBJS = $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

#//--Paths--//#
VPATH := .

#//--Compiler--//#
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -I$(INC_DIR)

#//--Rules--//#
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "Linking complete: $(NAME)"

$(BUILD_PATH)%.o: %.cpp | $(BUILD_PATH)
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)

-include $(DEPS)

clean:
	rm -rf $(BUILD_PATH)
	@echo "Cleaned object files."
fclean: clean
	rm -rf $(NAME)
	@echo "Cleaned executable."
re: fclean all

.PHONY: all clean fclean re