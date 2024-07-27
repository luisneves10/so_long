/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:55:31 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/10 14:13:44 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_a(t_data *data)
{
	player_img_update('a', data);
	left_collisions(data);
	check_collectibles(data);
	check_trap(data);
	check_exit(data);
	++data->p_moves;
}

void	move_d(t_data *data)
{
	player_img_update('d', data);
	right_collisions(data);
	check_collectibles(data);
	check_trap(data);
	check_exit(data);
	++data->p_moves;
}

void	move_w(t_data *data)
{
	player_img_update('w', data);
	up_collisions(data);
	check_collectibles(data);
	check_trap(data);
	check_exit(data);
	++data->p_moves;
}

void	move_s(t_data *data)
{
	player_img_update('s', data);
	down_collisions(data);
	check_collectibles(data);
	check_trap(data);
	check_exit(data);
	++data->p_moves;
}
