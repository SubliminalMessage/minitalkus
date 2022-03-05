### ---   ---   ---         ---   ---   --- ###
#             PROJECT COMPILATION             #
### ---   ---   ---         ---   ---   --- ###

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address

### ---   ---   ---         ---   ---   --- ###
#               PROJECT PATHS                 #
### ---   ---   ---         ---   ---   --- ###

INCS_PATH			= include/
SRCS_PATH			= srcs/
BIN_PATH			= bin/

### ---   ---   ---         ---   ---   --- ###
#               PROJECT FILES                 #
### ---   ---   ---         ---   ---   --- ###

NAME		= libftprintf.a

SRCS		=	ft_printf.c					\
				print_specials.c			\
				ft_itoa.c					\
				util_functions.c			

OBJS = $(SRCS:%.c=bin/%.o)
### ---   ---   ---         ---   ---   --- ###
#              COLORS & EXTRAS :)             #
### ---   ---   ---         ---   ---   --- ###

RED		= '\033[1;31m'
GREEN	= '\033[1;32m'
PURPLE	= '\033[1;35m'
YELLOW	= '\033[1;33m'
WHITE	= '\033[1;37m'
BLUE	= '\033[1;34m'

### ---   ---   ---         ---   ---   --- ###
#                  GAME RULES                 #
### ---   ---   ---         ---   ---   --- ###

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(PURPLE)"[Creating $(NAME) "$(PURPLE)"]"$(WHITE)
	@rm -rf $(NAME)
	ar -rcs $(NAME) $(OBJS)

bin/%.o: srcs/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	$(CC) $(CFLAGS) -I $(INCS_PATH) -c $< -o $@

clean:
	@echo $(RED)"[Deleting Object Files]"$(WHITE)
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf	$(INCS_PATH)/ft_printf.h.gch

fclean: clean 
	@echo $(RED)"[Deleting $(NAME)]"$(WHITE)
	@rm -rf $(NAME)

re: fclean all