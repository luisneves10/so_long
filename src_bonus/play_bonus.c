/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:40 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/02 09:56:41 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_player(int keysym, t_data *data)
{
	if (keysym == XK_w)
		move_w(data);
	else if (keysym == XK_a)
		move_a(data);
	else if (keysym == XK_s)
		move_s(data);
	else if (keysym == XK_d)
		move_d(data);
	if (data->c_count == 0)
	{
		data->c_count --;
		exit_img_update(data);
	}
	draw_map(data);
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_game(data);
	move_player(keysym, data);
	return (0);
}

void	play(t_data *data)
{
	mlx_hook(data->win.win_ptr, KeyPress, KeyPressMask, keypress, data);
	mlx_hook(data->win.win_ptr, DestroyNotify,
		StructureNotifyMask, exit_game, data);
}
