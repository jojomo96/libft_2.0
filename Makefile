NAME        := libft.a
CC          ?= cc
AR          ?= ar
RANLIB      ?= ranlib

CFLAGS      ?= -Wall -Wextra -Werror -std=gnu17

INC_DIR     := include
SRC_DIR     := src
OBJ_DIR     := obj

INCLUDES    := -I$(INC_DIR)

SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Optional: tiny test runner (matches your CMake setup)
TEST_NAME   := test_runner
TEST_SRC    := tests/test_main.c

.PHONY: all clean fclean re bonus test

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^
	$(RANLIB) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

re: fclean all

# If you ever have 42-style "bonus" sources, you can hook them up here.
bonus: all

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_SRC) $(NAME) -o $(TEST_NAME)
	./$(TEST_NAME)

