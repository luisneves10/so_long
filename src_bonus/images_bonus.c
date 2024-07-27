/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:40:52 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/01 10:32:54 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_img	new_file_img(t_win window, char *file)
{
	t_img	image;

	image.win = window;
	image.img = mlx_xpm_file_to_image(window.mlx_ptr, file, &image.w, &image.h);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len)
			+ (x * img.bpp / 8))));
}

void	overlay_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
