/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:47:22 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 14:13:10 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define TILE 64
# define PACE 10

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

typedef struct s_walk
{
	int		right;
	int		left;
	int		up;
	int		down;
}	t_walk;

/*	0 -> background		*/
/*	1 -> wall			*/
/*	2 -> exit			*/
/*	3 -> collectible	*/
/*	4 -> player			*/
/*	5 -> base_image		*/
/*	6 -> trap			*/

typedef struct s_data
{
	t_win	win;
	char	**map;
	int		map_w;
	int		map_h;
	t_img	img[7];
	t_point	begin;
	t_point	pp;
	t_walk	walk;
	int		c_count;
	int		p_count;
	int		e_count;
	int		p_moves;
}	t_data;

/*-------------------------------------------------------------- DATA INIT ---*/
void			data_init(t_data *data, char *str);
char			**parse_map(char *argv);

/*-------------------------------------------------------------- VALID MAP ---*/
int				valid_file(char *str);
int				valid_map(t_data *data);
int				is_rectangular(char **map);
int				is_closed(char **map);
int				is_pec(t_data *data);
int				valid_chars(char **map);
int				flood_fill(t_data *data);

/*------------------------------------------------------ WINDOW AND IMAGES ---*/
void			init_game(t_data *data);
t_img			new_img(int w, int h, t_win window);
t_img			new_file_img(t_win window, char *file);
void			put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			overlay_img(t_img dst, t_img src, int x, int y);
void			play(t_data *data);
int				draw_map(t_data *data);
void			player_img_update(char key, t_data *data);
void			exit_img_update(t_data *data);
void			display_player_moves(t_data *data);

/*------------------------------------------------------------ PLAYER MOVES---*/
void			move_w(t_data *data);
void			move_a(t_data *data);
void			move_s(t_data *data);
void			move_d(t_data *data);

void			left_collisions(t_data *data);
void			right_collisions(t_data *data);
void			up_collisions(t_data *data);
void			down_collisions(t_data *data);

void			walk_right(t_data *data);
void			walk_left(t_data *data);
void			walk_up(t_data *data);
void			walk_down(t_data *data);

void			check_collectibles(t_data *data);
void			check_exit(t_data *data);
void			check_trap(t_data *data);

int				is_collectible(t_data *data);
int				is_trap(t_data *data);
int				is_exit(t_data *data);

/*-------------------------------------------------------------- EXIT GAME ---*/
void			free_map(char **map);
int				exit_game(t_data *data);
void			error_message(int argc, char **argv);

#endif
