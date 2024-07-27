/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:07:28 by username          #+#    #+#             */
/*   Updated: 2024/06/27 10:57:28 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\nYou must choose a map\n", 2);
		exit (1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Error\nYou must choose only one map\n", 2);
		exit (1);
	}
	else if (!valid_file(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		exit (1);
	}
}
