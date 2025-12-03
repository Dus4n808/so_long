/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:10:08 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 11:00:45 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	is_rectangular(char **map)
{
	int	width;
	int	height;
	int	i;

	width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			error_msg_and_free("The map is not rectangular\n", map);
		i++;
	}
	height = i;
}

static void	is_good_wall(char **map)
{
	int	height;
	int	width;
	int	i;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			error_msg_and_free("Invalid Wall\n", map);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			error_msg_and_free("Invalid Wall\n", map);
		i++;
	}
}

void	check_shape_map(char **map)
{
	is_rectangular(map);
	is_good_wall(map);
}
