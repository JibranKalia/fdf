# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/12 20:12:00 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= libgfx.a
CC		:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes -I ../libmlx -I ../libft/includes -I ../includes

FILES		:= ft_putpixel ft_drawline
SRC		:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME) $(CLIENT) $(TEST)

$(LIBFT):
	@make -C libft	

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mCreated LIBGFX\033[0m"
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mRemoved LIBGFX\033[0m"

re: fclean all
