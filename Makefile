CC = cc
CFLAGS = -Wall -Werror -Wextra


HEAD_M = ./mandatory/push_swap.h
HEAD_G = ./gnl/get_next_line.h
HEAD_B = ./push_swap_bonus/checker.h

OBJS = \
aia.c \
merge.c \
position.c \
push_count.c \
push_pop.c \
push_sort_rules.c \
push_sort.c \
push_sort2.c \
push_split.c \
push_swap_utils.c \
push_swap_utils2.c \
push_swap.c \
push.c \
reverse_rotate.c \
rotate.c \
strset.c \
swap.c \

OBJS_CHECKER = \
aia_bonus.c \
checker.c \
push_bonus.c \
swap_bonus.c \
rotate_bonus.c \
reverse_rotate_bonus.c \
merge_bonus.c \
push_pop_bonus.c \
split_bonus.c \
helper_bonus.c \
main.c \
str_bonus.c \
utils_bonus.c \

SRCS = $(addprefix mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix push_swap_bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:.c=.o)
SRCS_BONUS_FILES = $(SRCS_BONUS:.c=.o)

MAND_DIR = mandatory
BONUS_DIR = push_swap_bonus

NAME = push_swap
BONUS = checker
RM = rm -rf

all : 
	@make $(NAME)

%.o: %c
	@$(CC) $(CFLAGS) -c $< -I $(HEAD_B) -I $(HEAD_M) -I $(HEAD_G)

$(NAME) : $(SRCS_FILES)
	@make -C ./gnl
	@$(CC) $(CFLAGS) ./gnl/get_next_line.a -o $@ $^

$(BONUS) : $(SRCS_BONUS_FILES)
	# @make -C ./gnl
	@$(CC) $(CFLAGS) ./gnl/get_next_line.a -o $@ $^

gnl :
	@make -C ./mandatory/gnl
	@make -C ./push_swap_bonus/gnl

bonus : 
	make $(BONUS)

clean :
	@make -C ./gnl clean
	@$(RM) $(SRCS_FILES)
	@$(RM) $(SRCS_BONUS_FILES)

fclean : clean
	@make -C ./gnl fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)


re :
	@make fclean
	@make all

.PHONY: all clean fclean re bonus
