NAME = libasm.a
TEST_FILE = test

AS = nasm
ASFLAGS = -f elf64

CC = clang
CFLAGS = -Wall -Werros -Wextra

RM = rm -rf

INC_DIR = ./inc/
A_SRC_DIR = ./src/
C_SRC_DIR = ./tests/

INCLUDES = -I $(INC_DIR)

C_SRC_FILES = main.c \
				test_strlen.c \
				test_strcpy.c \
				test_strcmp.c \
				test_write.c \
				test_read.c \
				test_strdup.c

A_SRC_FILES = ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s

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
	$(RM) tests_write
	$(RM) $(A_OBJS) $(C_OBJS) $(TEST_FILE)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
