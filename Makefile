# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/12 14:24:54 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror -O2
CFLAGS		+= -I includes/ -I libft/includes/ -I libmlx
LDFLAGS		:= -L libft/ -lft -L libmlx/ -lmlx -framework OpenGL -framework AppKit

LIBFT		:= libft/libft.a
LIBMLX		:= libmlx/libmlx.a

FILES		+= fdf_main fdf_reader fdf_draw fdf_point
#FILES		+= alloc_wrap

SRC		:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@make -C libmlx
	
$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@


$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCreated FDF\033[0m"

clean:
#	@make -C libmlx clean
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved FDF\033[0m"

re: fclean all
