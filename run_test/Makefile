NAME = minishell
LIBFT = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
LIB_DIR = ./libft
SRCS_DIR = ./srcs
BLT_DIR = ./builtin

SRCS = $(addprefix $(SRCS_DIR)/,)

TEST_SRCS = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(BLT_DIR)/*.c)


all : $(NAME)

$(NAME) : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./ -lft -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

test : $(LIBFT)
	$(CC) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -L ./ -lft $(TEST_SRCS)
	./a.out
	rm a.out
