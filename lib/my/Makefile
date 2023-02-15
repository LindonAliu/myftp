##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FreeKOSOVO
##

NAME		=	../libmy.a
SRCS		=	$(wildcard sources/*.c)
OBJS		=	$(SRCS:sources/%.c=obj/%.o)

ARCHIVER	=	ar
CC			:=	gcc
RM 			=	rm -f

HEADER		=	include/*
H_DEST		=	../../include

CPPFLAGS	+=	-Wall -Wextra -iquote include
CFLAGS		+=

obj/%.o:	sources/%.c
	@mkdir -p obj
	$(CC) $(CPPFLAGS) -c $< -o $@

all:	header $(NAME)

header:
	@mkdir -p $(H_DEST)
	@cp $(HEADER) $(H_DEST)
	@printf "\033[0;33mheader copied to $(H_DEST)\n\033[0;37m"

$(NAME):	$(OBJS)
	@$(ARCHIVER) rc $(NAME) $(OBJS)
	@printf "\033[0;32mlibrary built\n\033[0;37m"

debug:	CPPFLAGS += -g3
debug:	re

re: fclean all

clean:
	@$(RM) $(OBJS)
	@$(RM) -r obj

fclean:	clean
	@$(RM) $(NAME)
	@printf "\033[0;31mlibrary cleaned successfully\n\033[0;37m"

.PHONY: all debug re clean fclean
