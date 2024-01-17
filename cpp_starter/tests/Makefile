##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for Google Test
##

NAME        := 	unit_tests
CXX         := 	g++

INC_DIR     := 	../include/
SRC_DIR     := 	../src/
COV_DIR     := 	./coverage/
OBJ_DIR     := 	./obj/

CXXFLAGS    := 	-Wall -Wextra -Werror -Wpedantic
CPPFLAGS	:= 	-iquote $(INC_DIR)
GCOVRFLAGS  := 	--branches --sort-uncovered
HTMLFLAGS   := 	--html --html-details
LDLIBS      := 	-lgtest -lgtest_main -pthread -lgcov

SRCS        := 	$(filter-out $(SRC_DIR)main.cpp, $(wildcard $(SRC_DIR)*.cpp))
TEST_SRCS   := 	$(wildcard *.cpp)

SRC_OBJS    := 	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))
TEST_OBJS   := 	$(patsubst %.cpp,$(OBJ_DIR)%.o,$(TEST_SRCS))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CXX) -c --coverage -o $@ $< $(CXXFLAGS) $(CPPFLAGS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(CPPFLAGS)

$(NAME): $(SRC_OBJS) $(TEST_OBJS)
	$(CXX) -o $(NAME) $(SRC_OBJS) $(TEST_OBJS) $(LDLIBS)
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
