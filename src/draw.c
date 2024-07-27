/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:38:23 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:53 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_data *data, t_img img, int x, int y)
{
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, img.img,
		x * img.w, y * img.h);
}

void	draw_player(t_data *data, t_img img, int x, int y)
{
	data->player.x = x;
	data->player.y = y;
	draw_img(data, img, x, y);
}

void	player_img_update(char key, t_data *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img[4].img);
	if (key == 'w')
		data->img[4] = new_file_img(data->win, "./textures/PW.xpm");
	if (key == 'a')
		data->img[4] = new_file_img(data->win, "./textures/PA.xpm");
	if (key == 's')
		data->img[4] = new_file_img(data->win, "./textures/PS.xpm");
	if (key == 'd')
		data->img[4] = new_file_img(data->win, "./textures/PD.xpm");
}

void	exit_img_update(t_data *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img[2].img);
	data->img[2] = new_file_img(data->win, "./textures/E2.xpm");
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0')
				draw_img(data, data->img[0], x, y);
			else if (data->map[y][x] == '1')
				draw_img(data, data->img[1], x, y);
			else if (data->map[y][x] == 'E')
				draw_img(data, data->img[2], x, y);
			else if (data->map[y][x] == 'C')
				draw_img(data, data->img[3], x, y);
			else if (data->map[y][x] == 'P')
				draw_player(data, data->img[4], x, y);
			x++;
		}
		y++;
	}
	return (0);
}
