/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:56:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/25 16:28:55 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(char **map)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (map[size + 1])
		size++;
	i = 0;
	while (map[i])
	{
		j = -1;
		if (i == 0 || i == size)
		{
			while (map[i][++j])
				if (map[i][j] != '1')
					return (0);
		}
		else
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
		i++;
	}
	return (1);
}

int	is_pec(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'C')
				data->c_count++;
			else if (data->map[y][x] == 'E')
				data->e_count++;
			else if (data->map[y][x] == 'P')
			{
				data->p_count++;
				data->begin.x = x;
				data->begin.y = y;
			}
		}
	}
	if (data->c_count == 0 || data->e_count != 1 || data->p_count != 1)
		return (0);
	return (1);
}

int	valid_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P'
				&& map[y][x] != 'E' && map[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_map(t_data *data)
{
	if (is_rectangular(data->map) && is_closed(data->map) && is_pec(data)
		&& valid_chars(data->map) && flood_fill(data))
		return (1);
	free_map(data->map);
	return (0);
}
