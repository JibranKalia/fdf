# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/15 17:03:31 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror -O2
CFLAGS		+= -I includes/ -I libft/includes/ -I libmlx
CFLAGS		+= -I libgfx/includes/
LDFLAGS		:= -L libft/ -lft -L libmlx/ -lmlx -framework OpenGL -framework AppKit

LIBFT		:= libft/libft.a
LIBMLX		:= libmlx/libmlx.a
LIBGFX		:= libgfx/libgfx.a

FILES		+= fdf_main fdf_reader fdf_point
#FILES		+= alloc_wrap

SRC		:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C libmlx

$(LIBGFX):
	@make -C libgfx
	
$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ) $(LIBGFX)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCreated FDF\033[0m"

clean:
	@make -C libmlx clean
	@make -C libgfx clean
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@make -C libgfx fclean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved FDF\033[0m"

re: fclean all
