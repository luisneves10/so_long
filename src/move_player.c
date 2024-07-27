/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:55:31 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/21 15:04:58 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_a(t_data *data)
{
	player_img_update('a', data);
	if (data->map[data->player.y][data->player.x - 1] == 'E'
		&& data->c_count == -1)
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		data->map[data->player.y][data->player.x] = '0';
		data->player.x --;
		data->map[data->player.y][data->player.x] = 'P';
		exit_game(data);
	}
	else if (data->map[data->player.y][data->player.x - 1] == '1'
		|| data->map[data->player.y][data->player.x - 1] == 'E')
		return ;
	else
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		if (data->map[data->player.y][data->player.x - 1] == 'C')
			data->c_count --;
		data->map[data->player.y][data->player.x] = '0';
		data->player.x --;
		data->map[data->player.y][data->player.x] = 'P';
	}
	ft_printf("Player moves: %i\n", ++data->p_moves);
}

void	move_d(t_data *data)
{
	player_img_update('d', data);
	if (data->map[data->player.y][data->player.x + 1] == 'E'
		&& data->c_count == -1)
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		data->map[data->player.y][data->player.x] = '0';
		data->player.x ++;
		data->map[data->player.y][data->player.x] = 'P';
		exit_game(data);
	}
	else if (data->map[data->player.y][data->player.x + 1] == '1'
		|| data->map[data->player.y][data->player.x + 1] == 'E')
		return ;
	else
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		if (data->map[data->player.y][data->player.x + 1] == 'C')
			data->c_count --;
		data->map[data->player.y][data->player.x] = '0';
		data->player.x ++;
		data->map[data->player.y][data->player.x] = 'P';
	}
	ft_printf("Player moves: %i\n", ++data->p_moves);
}

void	move_w(t_data *data)
{
	player_img_update('w', data);
	if (data->map[data->player.y - 1][data->player.x] == 'E'
		&& data->c_count == -1)
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		data->map[data->player.y][data->player.x] = '0';
		data->player.y --;
		data->map[data->player.y][data->player.x] = 'P';
		exit_game(data);
	}
	else if (data->map[data->player.y - 1][data->player.x] == '1'
		|| data->map[data->player.y - 1][data->player.x] == 'E')
		return ;
	else
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		if (data->map[data->player.y - 1][data->player.x] == 'C')
			data->c_count --;
		data->map[data->player.y][data->player.x] = '0';
		data->player.y --;
		data->map[data->player.y][data->player.x] = 'P';
	}
	ft_printf("Player moves: %i\n", ++data->p_moves);
}

void	move_s(t_data *data)
{
	player_img_update('s', data);
	if (data->map[data->player.y + 1][data->player.x] == 'E'
		&& data->c_count == -1)
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		data->map[data->player.y][data->player.x] = '0';
		data->player.y ++;
		data->map[data->player.y][data->player.x] = 'P';
		exit_game(data);
	}
	else if (data->map[data->player.y + 1][data->player.x] == '1'
		|| data->map[data->player.y + 1][data->player.x] == 'E')
		return ;
	else
	{
		mlx_clear_window(data->win.mlx_ptr, data->win.win_ptr);
		if (data->map[data->player.y + 1][data->player.x] == 'C')
			data->c_count --;
		data->map[data->player.y][data->player.x] = '0';
		data->player.y ++;
		data->map[data->player.y][data->player.x] = 'P';
	}
	ft_printf("Player moves: %i\n", ++data->p_moves);
}
