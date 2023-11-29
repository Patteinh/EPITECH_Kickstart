##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		:=	unit_tests
CC			:=	gcc

INC_DIR		:=	../include/
LIBINC_DIR	:=	../lib/include/
SRC_DIR		:=	../src/
COV_DIR		:=	./coverage/
OBJ_DIR		:=	./obj/

CFLAGS		:=	-Wall -Wextra -Werror -Wpedantic
CPPFLAGS	:=	-I$(INC_DIR) -I$(LIBINC_DIR)
GCOVRFLAGS	:=	--branches --sort-uncovered
HTMLFLAGS	:=	--html --html-details
LDLIBS		:=	-lcriterion -lgcov

SRCS		:=	$(filter-out $(SRC_DIR)main.c, $(wildcard $(SRC_DIR)*.c))
TEST_SRCS	:=	$(wildcard *.c)

SRC_OBJS	:=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
TEST_OBJS	:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(TEST_SRCS))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) -c --coverage -o $@ $< $(CFLAGS) $(CPPFLAGS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

$(NAME): $(SRC_OBJS) $(TEST_OBJS)
	$(CC) -o $(NAME) $(SRC_OBJS) $(TEST_OBJS) $(LDLIBS)
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
