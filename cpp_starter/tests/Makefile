##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		:=	unit_tests
CXX			:=	g++

SRC_DIR		:=	../src/
COV_DIR		:=	./coverage/
OBJ_DIR		:=	./obj/

CXXFLAGS	:=	-Wall -Wextra -Werror -Wpedantic
GCOVRFLAGS	:=	--branches --sort-uncovered
HTMLFLAGS	:=	--html --html-details
LDLIBS		:=	-lcriterion -lgcov

SRCS		:=	$(filter-out $(SRC_DIR)main.cpp, $(wildcard $(SRC_DIR)*.cpp))
TEST_SRCS	:=	$(wildcard *.cpp)

SRC_OBJS	:=	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))
TEST_OBJS	:=	$(patsubst %.cpp,$(OBJ_DIR)%.o,$(TEST_SRCS))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CXX) -c --coverage -o $@ $< $(CXXFLAGS)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(NAME): $(SRC_OBJS) $(TEST_OBJS)
	$(CXX) -o $(NAME) $(SRC_OBJS) $(TEST_OBJS) $(LDLIBS)
	./$(NAME) --verbose
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
