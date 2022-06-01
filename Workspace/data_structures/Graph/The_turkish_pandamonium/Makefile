CFLAGS	= gcc -glldb -Wall -Wextra -Werror -o
NAME	= push_swap

SRC = src/push_swap.c src/sort_3.c \
	rules/stack_utilities_1.c rules/stack_utilities_2.c rules/reverse_rotate.c rules/rotate.c rules/swap_push.c \
	tree/duplicate_search.c tree/deletion.c tree/avl_tree_utilities.c tree/insert.c tree/rotation.c \

all: credit $(NAME)
	@echo "██████████████████ Compiled ██████████████████"
	@echo "\033[1;33mMartini\033[m"
$(NAME):
	@$(MAKE) -C libft/ re
	$(CFLAGS) $(NAME) $(SRC) -L libft/ -lft -I inc

clean:
	@$(MAKE) -C libft/ clean

fclean: fclean
	rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re: fclean all

credit:
	@echo " __ __   __   ___  _____  _  __  _  _ "
	@echo "|  V  | /  \ | _ \|_   _|| ||  \| || |"
	@echo "| \_/ || /\ || v /  | |  | || | ' || |"
	@echo "|_| |_||_||_||_|_\  |_|  |_||_|\__||_|"
	@echo "                         \033[0;95mAlp A. Yalman\033[m"