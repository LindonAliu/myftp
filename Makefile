##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make nice stuff
##

SRC_ALL		=	

SRC_NT		=	main.c

CC			:=	gcc

SRC_TEST	=	tests_redirect_output.c

SRC_EXEC	=	$(SRC_ALL) $(SRC_NT)

OBJ_EXEC	=	$(SRC_EXEC:%.c=obj/build/%.o)
OBJ_TEST	=	$(SRC_TEST:%.c=obj/tests/%.o) $(SRC_ALL:%.c=obj/debug/%.o)

LIBMY		=	lib/libmy.a
DEBUGFLAGS	+=

EXEC		=	myftp

TEST		=	unit_tests

CPPFLAGS	+=	-Wall -Wextra -iquote "include" -g3
CFLAGS		+=
LDFLAGS		=	-Llib -lmy

all:	$(EXEC)

tests_run:	clean_cov $(TEST)
	@./$(TEST) && printf "all tests are executed\n"
	@printf "\033[0;31mcoverage :\n\033[0;37m" && gcovr --exclude tests
	@printf "\033[0;31mbranches coverage :\n\033[0;37m" && gcovr --branches --exclude tests

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
	@$(CC) -o $(EXEC) $(OBJ_EXEC) $(LDFLAGS) && printf "\033[0;32mexecutable built\n\033[0;37m"

$(TEST):	$(LIBMY) $(OBJ_TEST)
	$(CC) -o $(TEST) $(OBJ_TEST) $(LDFLAGS) -lcriterion --coverage

$(LIBMY):
	$(MAKE) $(DEBUGFLAGS) -C lib/my

clean_cov:
	@find . \( -name "#*#" -or -name "*~" -or -name "*.gcda"  \) -delete

clean:	clean_cov
	@$(MAKE) clean -C lib/my
	@find . -name "*.gcno" -delete
	@rm -f $(OBJ_EXEC) $(OBJ_TEST)
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
