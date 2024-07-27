/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:51:29 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 10:37:46 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_init(t_data *data)
{
	data->img[0] = new_file_img(data->win, "./textures/0.xpm");
	data->img[1] = new_file_img(data->win, "./textures/1.xpm");
	data->img[2] = new_file_img(data->win, "./textures/0.xpm");
	data->img[3] = new_file_img(data->win, "./textures/C.xpm");
	data->img[4] = new_file_img(data->win, "./textures/PS01.xpm");
	data->img[5] = new_img(data->win.w, data->win.h, data->win);
	data->img[6] = new_file_img(data->win, "./textures/T.xpm");
}

void	init_game(t_data *data)
{
	data->pp.x = (data->begin.x * TILE) + (TILE / 2);
	data->pp.y = (data->begin.y * TILE) + (TILE / 2) + 10;
	data->win.w = data->map_w * TILE;
	data->win.h = data->map_h * TILE;
	data->win.mlx_ptr = mlx_init();
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr,
			data->win.w, data->win.h, "so_long");
	if (data->win.w > 1920 || data->win.h > 1050)
	{
		ft_printf("WARNING: The map might be too big for the screen!\n");
		ft_printf("It might affect the gameplay...\n");
	}
	img_init(data);
	draw_map(data);
}
