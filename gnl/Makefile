CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

HEAD = get_next_line.h

SRC = get_next_line.c get_next_line_utils.c

SRC_BO = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BO = $(SRC_BO:.c=.o)

ifdef BONUS
	OBJ_SET = $(OBJ_BO)
else
	OBJ_SET = $(OBJ)
endif

all = $(NAME)

$(NAME) : $(OBJ_SET)
	ar -rsc $@ $^

.c.o :
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean :
	rm -rf $(OBJ) all bonus

fclean :
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

bonus :
	make BONUS=1 $(NAME)

.PHONY : all re clean fclean bonus
