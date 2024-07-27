/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:29:44 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 10:23:03 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_wall(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}

void	left_collisions(t_data *data)
{
	int	next_block_x;
	int	next_block_y;

	next_block_x = data->pp.x / TILE - 1;
	next_block_y = data->pp.y / TILE;
	if (is_wall(data, next_block_x, next_block_y))
	{
		if (data->pp.x - 10 - (next_block_x * TILE + TILE) >= PACE)
			data->pp.x -= PACE;
		else if (data->pp.x - 10 - (next_block_x * TILE + TILE) >= 0
			&& data->pp.x - 10 -(next_block_x * TILE + TILE) < PACE)
			data->pp.x -= data->pp.x - (next_block_x * TILE + TILE) - 10;
	}
	else
		data->pp.x -= PACE;
}

void	right_collisions(t_data *data)
{
	int	next_block_x;
	int	next_block_y;

	next_block_x = data->pp.x / TILE + 1;
	next_block_y = data->pp.y / TILE;
	if (is_wall(data, next_block_x, next_block_y))
	{
		if (data->pp.x + 10 - (next_block_x * TILE) <= -PACE)
			data->pp.x += PACE;
		if (data->pp.x + 10 - (next_block_x * TILE) <= 0
			&& data->pp.x + 10 - (next_block_x * TILE) > -PACE)
			data->pp.x += (next_block_x * TILE) - data->pp.x - 10;
	}
	else
		data->pp.x += PACE;
}

void	up_collisions(t_data *data)
{
	int	next_block_x;
	int	next_block_y;

	next_block_x = data->pp.x / TILE;
	next_block_y = data->pp.y / TILE - 1;
	if (is_wall(data, next_block_x, next_block_y))
	{
		if (data->pp.y - 5 - (next_block_y * TILE + TILE) >= PACE)
			data->pp.y -= PACE;
		else if (data->pp.y - 5 - (next_block_y * TILE + TILE) >= 0
			&& data->pp.y - 5 - (next_block_y * TILE + TILE) < PACE)
			data->pp.y -= data->pp.y - (next_block_y * TILE + TILE) - 5;
	}
	else
		data->pp.y -= PACE;
}

void	down_collisions(t_data *data)
{
	int	next_block_x;
	int	next_block_y;

	next_block_x = data->pp.x / TILE;
	next_block_y = data->pp.y / TILE + 1;
	if (is_wall(data, next_block_x, next_block_y))
	{
		if (data->pp.y + 5 - (next_block_y * TILE) <= -PACE)
			data->pp.y += PACE;
		else if (data->pp.y + 5 - (next_block_y * TILE) <= 0
			&& data->pp.y + 5 - (next_block_y * TILE) > -PACE)
			data->pp.y += (next_block_y * TILE) - data->pp.y - 5;
	}
	else
		data->pp.y += PACE;
}
