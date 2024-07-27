/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:47:22 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 12:17:31 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

/*	0 -> background		*/
/*	1 -> wall			*/
/*	2 -> exit			*/
/*	3 -> collectible	*/
/*	4 -> player			*/

typedef struct s_data
{
	t_win	win;
	char	**map;
	int		map_w;
	int		map_h;
	t_img	img[5];
	t_point	begin;
	int		c_count;
	int		p_count;
	int		e_count;
	t_point	player;
	int		p_moves;
}	t_data;

/*-------------------------------------------------------------- DATA INIT ---*/
void	data_init(t_data *data, char *str);
char	**parse_map(char *argv);

/*-------------------------------------------------------------- VALID MAP ---*/
int		valid_file(char *str);
int		valid_map(t_data *data);
int		is_rectangular(char **map);
int		is_closed(char **map);
int		is_pec(t_data *data);
int		valid_chars(char **map);
int		flood_fill(t_data *data);

/*------------------------------------------------------ WINDOW AND IMAGES ---*/
void	init_game(t_data *data);
t_img	new_file_img(t_win window, char *file);
int		draw_map(t_data *data);
void	draw_player(t_data *data, t_img img, int x, int y);
void	player_img_update(char key, t_data *data);
void	exit_img_update(t_data *data);

/*------------------------------------------------------------ PLAYER MOVES---*/
void	play(t_data *data);
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);

/*-------------------------------------------------------------- EXIT GAME ---*/
void	free_map(char **map);
int		exit_game(t_data *data);
void	error_message(int argc, char **argv);

#endif
