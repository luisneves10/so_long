/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:33:24 by luibarbo          #+#    #+#             */
/*   Updated: 2024/06/20 14:36:28 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	open_directory(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ft_putstr_fd("Error\nPath is a directory!\n", 2);
		exit (1);
	}
}

char	**parse_map(char *argv)
{
	int		fd;
	char	**map;
	char	*str;
	char	*tmp;

	open_directory(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	tmp = ft_strdup("");
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = ft_strjoin(tmp, str);
		free (str);
	}
	map = ft_split(tmp, '\n');
	free (tmp);
	close(fd);
	return (map);
}
