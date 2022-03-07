### ---   ---   ---         ---   ---   --- ###
#             PROJECT COMPILATION             #
### ---   ---   ---         ---   ---   --- ###

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

### ---   ---   ---         ---   ---   --- ###
#               PROJECT PATHS                 #
### ---   ---   ---         ---   ---   --- ###

INCS_PATH			= include/
SRCS_PATH			= src/
BIN_PATH			= bin/

### ---   ---   ---         ---   ---   --- ###
#               PROJECT FILES                 #
### ---   ---   ---         ---   ---   --- ###

NAME		= libftprintf.a

C_FILE		= client.c ft_atoi.c
S_FILE		= server.c

C_OBJ 		= $(C_FILE:%.c=bin/%.o)
S_OBJ 		= $(S_FILE:%.c=bin/%.o)

FT_PRINTF	= ft_printf/libftprintf.a

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

all: client server

$(FT_PRINTF):
	@make -C ft_printf/

client: $(FT_PRINTF) $(LIBFT) $(C_OBJ)
	@echo $(BLUE)"[Creating client]"$(WHITE)
	$(CC) $(CFLAGS) -I $(INCS_PATH) $(C_OBJ) $(FT_PRINTF) $(LIBFT) -o $@

server: $(FT_PRINTF) $(LIBFT) $(S_OBJ)
	@echo $(BLUE)"[Creating server]"$(WHITE)
	$(CC) $(CFLAGS) -I $(INCS_PATH) $(S_OBJ) $(FT_PRINTF) $(LIBFT) -o $@

bin/%.o: src/%.c
	@echo $(BLUE)"[Compilation]"$(WHITE)": $< "
	@mkdir -p bin
	$(CC) $(CFLAGS) -I $(INCS_PATH) -I ft_printf/include/ -c $< -o $@

clean:
	@echo $(RED)"[Deleting Object Files]"$(WHITE)
	@rm -rf bin
	@rm -rf	$(INCS_PATH)/minitalk.h.gch

fclean: clean 
	@echo $(RED)"[Deleting executables]"$(WHITE)
	@rm -rf client server

re: fclean all