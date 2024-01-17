##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME		:=	libmy.a
CC			:=	gcc

INC_DIR		:=	./include/
OBJ_DIR		:=	./obj/
CPPFLAGS	:=  -iquote $(INC_DIR)


SRCS 		:= 	$(shell find -name '*.c')
OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
