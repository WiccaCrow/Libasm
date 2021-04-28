NAME = libasm.a

TEST_1 = test1

TEST_2 = test2

FLAGS = -g -Wall -Wextra -Werror

NASM = nasm -f macho64

SRC = \
libasm_main/ft_strlen.s \
libasm_main/ft_strcpy.s \
libasm_main/ft_strcmp.s \
libasm_main/ft_write.s \
libasm_main/ft_read.s \
libasm_main/ft_strdup.s

SRC_TEST_1 = \
test_2/test2_0_main.c \
test_2/test2_1_strlen.c \
test_2/test2_2_strcpy.c \
test_2/test2_3_strcmp.c \
test_2/test2_6_strdup.c \
test_2/test2_4_write.c \
test_2/test2_5_read.c \

SRC_TEST_2 = \
test_1/test_main_1.c \
test_1/test_main_2.c \
test_1/test_main_3.c \
gnl/get_next_line_utils.c \
gnl/get_next_line.c

OBJ = $(SRC:.s=.o)
OBJ_TEST_1 = $(SRC_TEST_1:.c=.o)
OBJ_TEST_2 = $(SRC_TEST_2:.c=.o)

%.o: %.s
	$(NASM) $<

%.o:%.c
	gcc $(FLAGS) -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(TEST_1): $(NAME) $(OBJ_TEST_1)
	gcc $(FLAGS) -L. -lasm -o $(TEST_1) $(OBJ_TEST_1)
	./$(TEST_1)

$(TEST_2): $(NAME) $(OBJ_TEST_2)
	gcc $(FLAGS) -L. -lasm -o $(TEST_2) $(OBJ_TEST_2)
	./$(TEST_2)

clean: ; rm -rf $(OBJ) $(OBJ_TEST_1) $(OBJ_TEST_2)

fclean:	clean ; rm -rf $(NAME) $(TEST_1) $(TEST_2)

re: fclean all

.PHONY: all clean fclean re
