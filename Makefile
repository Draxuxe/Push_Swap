# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️ $(WHITE)] 
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=push_swap
CHECKER_NAME=checker

# Path
SRC_PATH = ./Sources/
OBJ_PATH = ./objs/
INCDIR = Includes

# Name
SRC_NAME = main.c                       \
		   ./Parsing/parser.c           \
		   ./Utils/stacks_utilities.c   \
		   ./Utils/utils_get.c          \
		   ./Utils/sorting_utils.c      \
		   ./Utils/opti_utils.c         \
		   ./Utils/pre_sort_utils.c     \
		   ./Functions/push.c           \
		   ./Functions/reverse_rotate.c \
		   ./Functions/rotate.c         \
		   ./Functions/swap.c           \
		   ./Sorting/sort.c

CHECKER_SRCS = Checker/checker.c                  \
			./Parsing/parser.c                    \
			./Functions/swap.c                    \
			./Functions/push.c                    \
			./Functions/rotate.c                  \
			./Functions/reverse_rotate.c          \
			./Sorting/sort.c                      \
			./Utils/stacks_utilities.c            \
			./Utils/utils_get.c                   \
			./Utils/sorting_utils.c               \
			./Utils/opti_utils.c                  \
			./Utils/pre_sort_utils.c              \
			../Get_next_line/get_next_line.c      \
			../Get_next_line/get_next_line_utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CHECKER_OBJ_NAME = $(CHECKER_SRCS:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CHECKER_SRC = $(addprefix $(SRC_PATH)/, $(CHECKER_SRCS))
CHECKER_OBJ = $(addprefix $(OBJ_PATH), $(CHECKER_OBJ_NAME))

# Libft
FT		= ./Libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./Libft
FT_LNK	= -L ./Libft -l ft

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror


all: obj $(FT_LIB) $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/utils
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/functions
	@mkdir -p $(OBJ_PATH)/sorting
	@mkdir -p $(OBJ_PATH)/stacks
	@mkdir -p $(OBJ_PATH)/checker
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@echo "$(INFO)Building libft library...$(NOC)"
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

$(NAME): $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

$(CHECKER_NAME): $(CHECKER_OBJ)
	@echo "$(INFO)Building $(CHECKER_NAME)...$(NOC)"
	@$(CC) $(CHECKER_OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(CHECKER_NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting $(CHECKER_NAME)...$(NOC)"
	@rm -rf $(CHECKER_NAME)
	@echo "$(SUCCESS)$(CHECKER_NAME) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

re: fclean all

.PHONY: all obj clean fclean re