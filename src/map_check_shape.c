/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:10:08 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 16:41:23 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_rectangular(char **map)
{
	int	width;
	int	height;
	int	i;

	width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	height = i;
	if (width == height)
		return (0);
	return (1);
}

static int	is_good_wall(char **map)
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
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_good_wall_and_shape(char **map)
{
	if (!is_rectangular(map))
	{
		ft_printf("Erreur\nMap non valide!\nN'est pas réctangulaire\n");
		return (0);
	}
	else if (!is_good_wall(map))
	{
		ft_printf("Erreur\nMap non valide!\nLes murs sont pas bon!\n");
		return (0);
	}
	return (1);
}
