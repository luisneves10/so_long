/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:38:23 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/03 16:24:10 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_img(t_data *data, t_img img, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img.img,
		x * img.w, y * img.h);
}

void	player_img_update(char key, t_data *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img[4].img);
	if (key == 'w')
		walk_up(data);
	if (key == 'a')
		walk_left(data);
	if (key == 's')
		walk_down(data);
	if (key == 'd')
		walk_right(data);
}

void	exit_img_update(t_data *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img[2].img);
	data->img[2] = new_file_img(data->win, "./textures/E2.xpm");
}

void	put_img(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'P'
		|| data->map[y][x] == 'C')
		overlay_img(data->img[5], data->img[0], x * TILE, y * TILE);
	else if (data->map[y][x] == '1')
		overlay_img(data->img[5], data->img[1], x * TILE, y * TILE);
	else if (data->map[y][x] == 'E')
		overlay_img(data->img[5], data->img[2], x * TILE, y * TILE);
	else if (data->map[y][x] == 'T')
		overlay_img(data->img[5], data->img[6], x * TILE, y * TILE);
	if (data->map[y][x] == 'C')
		overlay_img(data->img[5], data->img[3], x * TILE, y * TILE);
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			put_img(data, x, y);
	}
	overlay_img(data->img[5], data->img[4],
		data->pp.x - (TILE / 2), data->pp.y - (TILE / 2) - 10);
	draw_img(data, data->img[5], 0, 0);
	display_player_moves(data);
	return (0);
}
