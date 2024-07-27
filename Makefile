# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 11:40:48 by luibarbo          #+#    #+#              #
#    Updated: 2024/07/10 14:22:14 by luibarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

INCLUDE			=	-I include/
SRC_DIR			=	src/
SRC_BONUS_DIR	=	src_bonus/
OBJ_DIR			=	obj/
OBJ_BONUS_DIR	=	obj_bonus/
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
RM				=	rm -rf

# COLORS
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
B_GREEN		=	\033[1;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

LIBFT_DIR	=	libft/
MLX_DIR		=	minilibx-linux/
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_LIB		=	$(MLX_DIR)/libmlx_linux.a
LFLAGS		=	-L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lbsd -lXext -lX11 -lm

SRC_FILES	=	main.c parse_map.c valid_map.c exit_game.c init_game.c draw.c \
	play.c move_player.c data_init.c flood_fill.c error_message.c \

SRC_BONUS_FILES	= main_bonus.c parse_map_bonus.c valid_map_bonus.c \
	exit_game_bonus.c init_game_bonus.c draw_bonus.c play_bonus.c \
	move_player_bonus.c data_init_bonus.c flood_fill_bonus.c \
	error_message_bonus.c display_text_bonus.c images_bonus.c \
	collisions_bonus.c player_walk_bonus.c check_collectibles_bonus.c \
	check_exit_bonus.c check_trap_bonus.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_BONUS	=	$(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))

OBJ			=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_BONUS	=	$(SRC_BONUS:$(SRC_BONUS_DIR)%.c=$(OBJ_BONUS_DIR)%.o)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_BONUS_DIR)%.o : $(SRC_BONUS_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "[$(GREEN)$(NAME)$(DEF_COLOR)] $(B_GREEN)Ready to play!$(DEF_COLOR)"
	@echo "Write './so_long (map)' to start the game."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS_DIR) $(OBJ_BONUS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LFLAGS)
	@echo "[$(GREEN)$(NAME_BONUS)$(DEF_COLOR)] $(B_GREEN)Ready to play!$(DEF_COLOR)"
	@echo "Write './so_long_bonus (map)' to start the game."

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_BONUS_DIR)
	@echo "[$(GREEN)$(NAME)$(DEF_COLOR)] .o files cleaned"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "[$(GREEN)$(NAME)$(DEF_COLOR)] Cleaned!"

re: fclean all
	@echo "[$(GREEN)$(NAME)$(DEF_COLOR)] Cleaned and rebuilt successfully!"

.PHONY: all clean fclean re bonus
