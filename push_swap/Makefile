# **************************************************************************** #
#                                PUSH_SWAP                                     #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = $(SRCDIR)/main.c $(SRCDIR)/parsing.c $(SRCDIR)/utils.c $(SRCDIR)/utils_2.c $(SRCDIR)/operations.c $(SRCDIR)/sorting.c $(SRCDIR)/radix.c
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

LIBFT_DIR = $(INCDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBFTPRINTF_DIR = $(INCDIR)/ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

# Colors and Emojis
GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m
RESET = \033[0m
CHECK = ✅
CROSS = ❌
ARROW = ➡️
GEAR = ⚙️

# Default rule
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF)
	@echo "$(BLUE)$(ARROW) Linking objects and libraries...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(LIBFTPRINTF_DIR) -lftprintf
	@echo "$(GREEN)$(CHECK) Successfully built $(NAME)$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)$(GEAR) Building libft library...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)$(CHECK) libft library built!$(RESET)"

$(LIBFTPRINTF):
	@echo "$(YELLOW)$(GEAR) Building ft_printf library...$(RESET)"
	@make -s -C $(LIBFTPRINTF_DIR)
	@echo "$(GREEN)$(CHECK) ft_printf library built!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)$(GEAR) Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(CROSS) Cleaning object files...$(RESET)"
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(LIBFTPRINTF_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)$(CROSS) Removing $(NAME) binary...$(RESET)"
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(LIBFTPRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
