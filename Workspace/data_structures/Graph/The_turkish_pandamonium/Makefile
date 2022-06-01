CFLAGS	= gcc -Wall -Wextra -Werror -o
NAME	= a.pandamonium
# DEBUG
# CFLAGS = gcc -glldb -Wall -Wextra -Werror -o

SRC = src/dev/main.c src/dev/city_struct.c

all: credit $(NAME)
	@echo "██████████████████ Compiled ██████████████████"
	@echo "\033[1;33mMartini\033[m"
$(NAME):
	@$(MAKE) -C inc/libft/ re
	$(CFLAGS) $(NAME) $(SRC) -L inc/libft/ -lft -I inc

test: all
	./pandamonium

clean:
	@$(MAKE) -C inc/libft/ clean

fclean: fclean
	rm -f $(NAME)
	@$(MAKE) -C inc/libft/ fclean

re: fclean all

credit:
	@echo " __ __   __   ___  _____  _  __  _  _ "
	@echo "|  V  | /  \ | _ \|_   _|| ||  \| || |"
	@echo "| \_/ || /\ || v /  | |  | || | ' || |"
	@echo "|_| |_||_||_||_|_\  |_|  |_||_|\__||_|"
	@echo "                         \033[0;95mAlp A. Yalman\033[m"