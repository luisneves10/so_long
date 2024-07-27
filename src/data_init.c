/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:23:35 by username          #+#    #+#             */
/*   Updated: 2024/06/27 10:57:10 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_data *data, char *str)
{
	int	i;

	data->map = parse_map(str);
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	data->p_moves = 0;
	data->map_w = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
		i++;
	data->map_h = i;
}
