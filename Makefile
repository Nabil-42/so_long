# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabil <nabil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 10:05:48 by nabil             #+#    #+#              #
#    Updated: 2024/03/16 14:03:39 by nabil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
INCLUDES    = -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS        = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
RM          = rm -rf

SRC         = so_long.c \

OBJ_DIR     = bin
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
# COLORS

GREEN       = \033[0;32m
GREY        = \033[1;30m
PURPLE      = \033[0;93m
BLUE        = \033[0;94m
CYAN        = \033[0;36m
END_COLOR   = \033[0;39m

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(CYAN)[so_long]$(END_COLOR) so_long is ready !"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
