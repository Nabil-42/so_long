# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabil <nabil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 10:05:48 by nabil             #+#    #+#              #
#    Updated: 2024/04/06 14:01:48 by nabil            ###   ########.fr        #
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

SRC         = src/so_long.c \
				src/utils/move_keybord.c \
				src/utils/initialise_win.c \
				src/utils/error.c \
				src/utils/render_map.c \

SRC_BONUS   = bonus/so_long_bonus.c \
				src/utils/move_keybord.c \
				src/utils/initialise_win.c \
				bonus/error_bonus.c \
				src/utils/render_map.c \

OBJ_DIR     = bin
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS   = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

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

bonus: $(OBJ_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(NAME)
	@echo "$(CYAN)[so_long]$(END_COLOR) so_long bonus is ready !"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus
