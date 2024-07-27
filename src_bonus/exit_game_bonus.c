/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:35:08 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/21 09:26:45 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img[0].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[1].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[2].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[3].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[4].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[5].img);
	mlx_destroy_image(data->win.mlx_ptr, data->img[6].img);
	mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	mlx_destroy_display(data->win.mlx_ptr);
	free_map(data->map);
	free (data->win.mlx_ptr);
	exit (0);
}
