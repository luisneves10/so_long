/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_trap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:01:18 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 14:16:43 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_trap(t_data *data)
{
	int	x;
	int	y;

	x = data->pp.x / TILE;
	y = data->pp.y / TILE;
	if (data->map[y][x] == 'T')
		return (1);
	return (0);
}

void	check_trap(t_data *data)
{
	int	t_min_x;
	int	t_max_x;
	int	t_min_y;
	int	t_max_y;

	t_min_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) - 22;
	t_max_x = ((data->pp.x / TILE) * TILE) + (TILE / 2) + 23;
	t_min_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) - 1;
	t_max_y = ((data->pp.y / TILE) * TILE) + (TILE / 2) + 15;
	if (is_trap(data))
	{
		if ((data->pp.y >= t_min_y && data->pp.y <= t_max_y)
			&& (data->pp.x >= t_min_x && data->pp.x <= t_max_x))
		{
			ft_printf("You fell into a trap.\nGame Over!\n");
			exit_game(data);
		}
	}
}
