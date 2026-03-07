#//---Files--//#
NAME = phonebook
SRC_DIR = src
BUILD_PATH  = .build/
INC_DIR = includes

FILES = main
FILES += Phonebook

OBJS = $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

#//--Paths--//#
VPATH := .
VPATH := $(SRC_DIR)

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
	rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."
fclean: clean
	rm -rf $(NAME)
	@echo "Cleaned executable."
re: fclean all

.PHONY: all clean fclean re