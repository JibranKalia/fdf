# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/04/04 18:11:09 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME			:= fdf

CC				:= gcc

CFLAGS			+= -Wall -Wextra -Werror
CFLAGS			+= -I includes/ -I libft/includes/ -I libmlx/

LDFLAGS			:= -L libft/ -lft -L libmlx/ -lmlx -framework OpenGL -framework AppKit

LIBFT			:= libft/libft.a
LIBMLX			:= libmlx/libmlx.a

FILES			:= main \

SRC				:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ				:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C libmlx
	
$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\033[32mCompiled Project Object Files\033[0m"


$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCreated Executable\033[0m"

clean:
	@make -C libmlx clean
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
