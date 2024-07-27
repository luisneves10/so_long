/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:33:56 by username          #+#    #+#             */
/*   Updated: 2024/06/27 10:57:41 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill(t_data *data, char **tab, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y > data->map_h || cur.x < 0 || cur.x > data->map_w
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'T'
			|| tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(data, tab, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(data, tab, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(data, tab, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(data, tab, (t_point){cur.x, cur.y + 1}, to_fill);
}

int	flood_fill(t_data *data)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_calloc(sizeof(char *), data->map_h + 1);
	i = -1;
	while (++i < data->map_h)
		tab[i] = ft_strdup(data->map[i]);
	tab[i] = NULL;
	fill(data, tab, data->begin, tab[data->begin.y][data->begin.x]);
	i = -1;
	while (++i < data->map_h)
	{
		j = -1;
		while (++j < data->map_w)
		{
			if (tab[i][j] != '1' && tab[i][j] != 'F' && tab[i][j] != 'T')
			{
				free_map(tab);
				return (0);
			}
		}
	}
	free_map(tab);
	return (1);
}
