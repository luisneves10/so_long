/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:40:58 by luibarbo          #+#    #+#             */
/*   Updated: 2024/07/01 10:24:52 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_file(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc)
	{
		error_message(argc, argv);
		data_init(&data, argv[1]);
		if (valid_map(&data))
		{
			init_game(&data);
			play(&data);
			mlx_loop(data.win.mlx_ptr);
		}
		else
		{
			ft_putstr_fd("Error\nInvalid map\n", 2);
			exit (1);
		}
	}
	return (0);
}
