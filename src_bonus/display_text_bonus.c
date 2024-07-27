/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:47:01 by username          #+#    #+#             */
/*   Updated: 2024/06/26 11:49:10 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_player_moves(t_data *data)
{
	int		x;
	int		y;
	char	*moves;

	y = 39;
	while (y >= 25)
	{
		x = data->win.w / 2 - 53;
		while (x <= data->win.w / 2 + 53)
			x++;
		y--;
	}
	mlx_string_put(data->win.mlx_ptr, data->win.win_ptr,
		x - 105, 37, 0xffffff, "Player moves: ");
	moves = ft_itoa(data->p_moves);
	mlx_string_put(data->win.mlx_ptr, data->win.win_ptr,
		x - 22, 37, 0xffffff, moves);
	free (moves);
}
