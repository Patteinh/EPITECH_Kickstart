##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for Google Test
##

NAME        :=	unit_tests
CXX         := 	g++

INC_DIR     := 	../include/
LIBINC_DIR  := 	../lib/include/
SRC_DIR     := 	../src/
COV_DIR     := 	./coverage/
OBJ_DIR     := 	./obj/

CFLAGS      := 	-Wall -Wextra -Werror -Wpedantic
CPPFLAGS    := 	-iquote $(INC_DIR) -iquote $(LIBINC_DIR)
GCOVRFLAGS  := 	--branches --sort-uncovered
HTMLFLAGS   := 	--html --html-details
LDLIBS      := 	-lgtest -lgtest_main -pthread -lgcov

C_SRCS      := 	$(filter-out $(SRC_DIR)main.c, $(wildcard $(SRC_DIR)*.c))
TEST_SRCS   := 	$(wildcard *.cpp)

C_SRC_OBJS  := 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(C_SRCS))
TEST_OBJS   := 	$(patsubst %.cpp,$(OBJ_DIR)%.o,$(TEST_SRCS))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CXX) -x c -c --coverage -o $@ $< $(CFLAGS) $(CPPFLAGS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

$(NAME): $(C_SRC_OBJS) $(TEST_OBJS)
	$(CXX) -o $(NAME) $(C_SRC_OBJS) $(TEST_OBJS) $(LDLIBS)
	./$(NAME)
	mkdir -p $(COV_DIR)
	cd .. && gcovr $(GCOVRFLAGS) $(HTMLFLAGS) -o tests/$(COV_DIR)index.html
	cd .. && gcovr

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(COV_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
