/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:46:40 by dufama            #+#    #+#             */
/*   Updated: 2025/11/22 21:41:25 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**duplicate_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	find_player(char **map, int *py, int *px)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
static void	check_after_flood_fill(char **copy)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C')
				error_msg_and_free("Un coin est inatteignable\n", copy);
			if (copy[y][x] == 'E')
				error_msg_and_free("Une sortie est inatteignable\n", copy);
			x++;
		}
		y++;
	}
}
void	check_solvable(char **map)
{
	char	**copy;
	int		y;
	int		x;

	copy = duplicate_map(map);
	if (!copy)
		error_msg_and_free("Duplication impossible\n", map);
	find_player(map, &y, &x);
	flood_fill(copy, x, y);
	check_after_flood_fill(copy);
	free_map(copy);
}




