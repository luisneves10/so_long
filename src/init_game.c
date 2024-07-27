/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:51:29 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/21 15:14:21 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_file_img(t_win window, char *file)
{
	t_img	image;

	image.win = window;
	image.img = mlx_xpm_file_to_image(window.mlx_ptr, file, &image.w, &image.h);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	img_init(t_data *data)
{
	data->img[0] = new_file_img(data->win, "./textures/0.xpm");
	data->img[1] = new_file_img(data->win, "./textures/1.xpm");
	data->img[2] = new_file_img(data->win, "./textures/E.xpm");
	data->img[3] = new_file_img(data->win, "./textures/C.xpm");
	data->img[4] = new_file_img(data->win, "./textures/PS.xpm");
}

void	init_game(t_data *data)
{
	data->win.w = data->map_w * 64;
	data->win.h = data->map_h * 64;
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
