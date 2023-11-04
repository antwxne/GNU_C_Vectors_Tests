##
## EPITECH PROJECT, 2023
## C_Template
## File description:
## Makefile
##

TEST_NAME	=	unit_tests
TESTS_DIR	=	tests/

TESTS_SRC	=	$(addprefix $(TESTS_DIR), \
				vector2D.c \
				)
TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

CC	=	gcc
RM	?=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	=	-iquote ./include/
LDLIBS	=
LDFLAGS	=

all: tests_run

clean:
	$(RM) $(TESTS_OBJ)

fclean: clean
	$(RM) $(TEST_NAME)

re: fclean all

debug: CFLAGS += -g3 -O0
debug: re

tests_run: CFLAGS += -fprofile-arcs -ftest-coverage -g3 -O0
tests_run: LDLIBS += -lcriterion -lgcov
tests_run: SRC := $(filter-out $(addprefix $(SRC_DIR), main.c), $(SRC))
tests_run: $(OBJ) $(TESTS_OBJ)
	$(CC) -o $(TEST_NAME) $(TESTS_OBJ) $(LDFLAGS) $(LDLIBS)
	./$(TEST_NAME)

.PHONY: all clean fclean re debug tests_run
