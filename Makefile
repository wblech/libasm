NAME = libasm.a
TEST_FILE = test

AS = nasm
ASFLAGS = -f elf64

CC = clang
CFLAGS = -Wall -Werros -Wextra -fsanitize=address

RM = rm -rf

INC_DIR = ./inc/
A_SRC_DIR = ./src/
C_SRC_DIR = ./tests/

INCLUDES = -I $(INC_DIR)

C_SRC_FILES = main.c

A_SRC_FILES = ft_strlen.s

A_SRCS = $(addprefix $(A_SRC_DIR),$(A_SRC_FILES))
A_OBJS = $(A_SRCS:.s=.o)

C_SRCS = $(addprefix $(C_SRC_DIR),$(C_SRC_FILES))
C_OBJS = $(C_SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(A_OBJS)
	ar -rc $(NAME) $(A_OBJS)
	ranlib $(NAME)
	@echo "\033[1;32m[OK]\033[0m	\033[1;33mCreating \033[0m $(NAME)"
	@echo ""

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
	@echo "\033[1;32m[OK]\033[0m	\033[1;33mCompiling\033[0m $(@F)"

$(TEST_FILE): $(C_OBJS)
	$(CC) $(C_OBJS) $(INCLUDES) $(CFLAGS) -L. -lasm -o $@
	@echo "\033[1;32m[OK]\033[0m	\033[1;33mCreating \033[0m $(EXEC_FILE)"

%.o:	%.c
	$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m	\033[1;33mCompiling\033[0m $(@F)"

clean:
	$(RM) $(A_OBJS) $(C_OBJS) $(TEST_FILE)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
