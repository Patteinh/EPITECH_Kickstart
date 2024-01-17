##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		:=	project
CC			:=	gcc

INC_DIR		:=	./include/
LIB_DIR		:=	./lib/
SRC_DIR		:=	./src/
TESTS_DIR	:=	./tests/
OBJ_DIR		:=	./obj/

CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	:=  -iquote $(INC_DIR) -iquote $(LIB_DIR)include/
LDFLAGS		:=  -L $(LIB_DIR)
LDLIBS		:=  -lmy
DEBUG		?=  -g3

SRCS		:=	$(shell find $(SRC_DIR) -name '*.c')
OBJS		:=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) | $(LIB_DIR)libmy.a
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_DIR)libmy.a:
	$(MAKE) -C $(LIB_DIR) CFLAGS="$(CFLAGS)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

debug: CFLAGS += $(DEBUG)
debug: all

tests_run:
	$(MAKE) -C $(TESTS_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(TESTS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) fclean -C $(TESTS_DIR)

re: fclean all

.PHONY: all debug tests_run clean fclean re
