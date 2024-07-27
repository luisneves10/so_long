/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:01:18 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 14:17:40 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_exit(t_data *data)
{
	int	x;
	int	y;

	x = data->pp.x / TILE;
	y = data->pp.y / TILE;
	if (data->map[y][x] == 'E')
		return (1);
	return (0);
}

void	check_exit(t_data *data)
{
	int	e_min_x;
	int	e_max_x;
	int	e_min_y;
	int	e_max_y;

	e_min_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) - 22;
	e_max_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) + 23;
	e_min_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) - 1;
	e_max_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) + 15;
	if (is_exit(data) && data->c_count == -1)
	{
		if ((data->pp.y >= e_min_y && data->pp.y <= e_max_y)
			&& (data->pp.x >= e_min_x && data->pp.x <= e_max_x))
		{
			ft_printf("Congratulations. You won!\n");
			exit_game(data);
		}
	}
}
