##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## FreeKOSOVO
##

SRC_ALL		= 	commands/cdup.c		\
				commands/cwd.c		\
				commands/dele.c		\
				commands/help.c		\
				commands/list.c		\
				commands/noop.c		\
				commands/pass.c		\
				commands/pasv.c		\
				commands/port.c		\
				commands/pwd.c		\
				commands/quit.c		\
				commands/retr.c		\
				commands/stor.c		\
				commands/user.c		\
				client.c			\
				account.c			\
				my_ftp.c			\
				server.c			\
				error_handling.c	\
				commands_handling.c	\
				manage_clients.c	\

SRC_NT		=	main.c

CC			:=	gcc

SRC_TEST	=	tests/* 	\
				sources/commands/cdup.c		\
				sources/commands/cwd.c		\
				sources/commands/dele.c		\
				sources/commands/help.c		\
				sources/commands/list.c		\
				sources/commands/noop.c		\
				sources/commands/pass.c		\
				sources/commands/pasv.c		\
				sources/commands/port.c		\
				sources/commands/pwd.c		\
				sources/commands/quit.c		\
				sources/commands/retr.c		\
				sources/commands/stor.c		\
				sources/commands/user.c		\
				sources/client.c			\
				sources/my_ftp.c			\
				sources/server.c			\
				sources/error_handling.c	\
				sources/commands_handling.c	\
				sources/manage_clients.c	\
				sources/account.c			\

SRC_EXEC	=	$(SRC_ALL) $(SRC_NT)

OBJ_EXEC	=	$(SRC_EXEC:%.c=obj/build/%.o)

LIBMY		=	lib/libmy.a
DEBUGFLAGS	+=

EXEC		=	myftp

TEST		=	unit_tests

CPPFLAGS	+=	-iquote "include"
CFLAGS		+=	-Wall -Wextra
LDFLAGS		=	-Llib -lmy

all:	$(EXEC)

tests_run:	clean_cov $(TEST)
	@./$(TEST) && printf "all tests are executed\n"
	@printf "\033[0;31mcoverage :\n\033[0;37m" && gcovr --exclude tests
	@printf "\033[0;31mbranches coverage :\n\033[0;37m" && gcovr --branches	\
	--exclude tests

obj/build/%.o:	sources/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

obj/debug/%.o:	sources/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) --coverage -c -o $@ $<

obj/tests/%.o:	tests/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(EXEC):	$(LIBMY) $(OBJ_EXEC)
	@$(CC) -o $(EXEC) $(OBJ_EXEC) $(LDFLAGS) \
		&& printf "\033[0;32mexecutable built\n\033[0;37m"

$(TEST):	CPPFLAGS += -lcriterion --coverage
$(TEST):	$(LIBMY)
	$(CC) -o $(TEST) $(SRC_TEST) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)

$(LIBMY):
	$(MAKE) $(DEBUGFLAGS) -C lib/my

clean_cov:
	@find . \( -name "#*#" -or -name "*~" -or -name "*.gcda"  \) -delete

clean:	clean_cov
	@$(MAKE) clean -C lib/my
	@find . -name "*.gcno" -delete
	@rm -f $(OBJ_EXEC)
	@rm -rf obj

fclean: clean
	@$(MAKE) fclean -C lib/my
	@rm -f $(EXEC) $(TEST)
	@printf "\033[0;31mclean successfull\n\033[0;37m"

debug: CFLAGS += -g3
debug: DEBUGFLAGS += debug
debug: re

re:	fclean all

.PHONY: all tests_run clean_cov clean fclean debug	re
