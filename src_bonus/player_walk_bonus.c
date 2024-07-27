/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:37:11 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/03 11:51:33 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	walk_right(t_data *data)
{
	if (data->walk.right == 1)
	{
		data->img[4] = new_file_img(data->win, "./textures/PD01.xpm");
		data->walk.right ++;
	}
	else if (data->walk.right == 2)
	{
		data->img[4] = new_file_img(data->win, "./textures/PD02.xpm");
		data->walk.right ++;
	}
	else if (data->walk.right == 3)
	{
		data->img[4] = new_file_img(data->win, "./textures/PD03.xpm");
		data->walk.right ++;
	}
	else if (data->walk.right == 4)
	{
		data->img[4] = new_file_img(data->win, "./textures/PD04.xpm");
		data->walk.right = 1;
	}
}

void	walk_left(t_data *data)
{
	if (data->walk.left == 1)
	{
		data->img[4] = new_file_img(data->win, "./textures/PA01.xpm");
		data->walk.left ++;
	}
	else if (data->walk.left == 2)
	{
		data->img[4] = new_file_img(data->win, "./textures/PA02.xpm");
		data->walk.left ++;
	}
	else if (data->walk.left == 3)
	{
		data->img[4] = new_file_img(data->win, "./textures/PA03.xpm");
		data->walk.left ++;
	}
	else if (data->walk.left == 4)
	{
		data->img[4] = new_file_img(data->win, "./textures/PA04.xpm");
		data->walk.left = 1;
	}
}

void	walk_up(t_data *data)
{
	if (data->walk.up == 1)
	{
		data->img[4] = new_file_img(data->win, "./textures/PW01.xpm");
		data->walk.up ++;
	}
	else if (data->walk.up == 2)
	{
		data->img[4] = new_file_img(data->win, "./textures/PW02.xpm");
		data->walk.up ++;
	}
	else if (data->walk.up == 3)
	{
		data->img[4] = new_file_img(data->win, "./textures/PW03.xpm");
		data->walk.up ++;
	}
	else if (data->walk.up == 4)
	{
		data->img[4] = new_file_img(data->win, "./textures/PW04.xpm");
		data->walk.up = 1;
	}
}

void	walk_down(t_data *data)
{
	if (data->walk.down == 1)
	{
		data->img[4] = new_file_img(data->win, "./textures/PS01.xpm");
		data->walk.down ++;
	}
	else if (data->walk.down == 2)
	{
		data->img[4] = new_file_img(data->win, "./textures/PS02.xpm");
		data->walk.down ++;
	}
	else if (data->walk.down == 3)
	{
		data->img[4] = new_file_img(data->win, "./textures/PS03.xpm");
		data->walk.down ++;
	}
	else if (data->walk.down == 4)
	{
		data->img[4] = new_file_img(data->win, "./textures/PS04.xpm");
		data->walk.down = 1;
	}
}
