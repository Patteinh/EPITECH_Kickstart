##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		:=	project
CXX			:=	g++

INC_DIR		:=	./include/
SRC_DIR		:=	./src/
TESTS_DIR	:=	./tests/
OBJ_DIR		:=	./obj/

CXXFLAGS	+=  -Wall -Wextra -Werror
CPPFLAGS	:= 	-iquote $(INC_DIR)
DEBUG		?=  -g3

SRCS		:=	$(shell find $(SRC_DIR) -name '*.cpp')
OBJS		:=	$(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $^ -o $@ $(CXXFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

debug: CXXFLAGS += $(DEBUG)
debug: all

tests_run:
	$(MAKE) -C $(TESTS_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(TESTS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(TESTS_DIR)

re: fclean all

.PHONY: all debug tests_run clean fclean re
