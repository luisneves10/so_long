/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:01:18 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 14:09:51 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_collectible(t_data *data)
{
	int	x;
	int	y;

	x = data->pp.x / TILE;
	y = data->pp.y / TILE;
	if (data->map[y][x] == 'C')
		return (1);
	return (0);
}

void	check_collectibles(t_data *data)
{
	int	c_min_x;
	int	c_max_x;
	int	c_min_y;
	int	c_max_y;

	c_min_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) - 7;
	c_max_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) + 7;
	c_min_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) - 7;
	c_max_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) + 7;
	if (is_collectible(data))
	{
		if ((data->pp.y >= c_min_y && data->pp.y <= c_max_y)
			&& (data->pp.x >= c_min_x && data->pp.x <= c_max_x))
		{
			data->map[data->pp.y / TILE][data->pp.x / TILE] = '0';
			data->c_count --;
		}
	}
}
