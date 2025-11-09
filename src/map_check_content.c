/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:37:45 by dufama            #+#    #+#             */
/*   Updated: 2025/11/09 17:56:18 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01CPE", map[i][j]))
			{
				ft_printf("Erreur\nCaractère invalide!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (ft_printf("Erreur\nNombre de joueurs\n"), 0);
	return (1);
}

static int	check_coin(char **map)
{
	int	i;
	int	j;
	int	coin;

	i = 0;
	coin = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	if (coin < 1)
		return (ft_printf("Erreur\nNombres de coins\n"), 0);
	return (1);
}

static int	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (ft_printf("Erreur\nNombre de sorties\n"), 0);
	return (1);
}

int	is_valid_map(char **map)
{
	if (!is_good_wall_and_shape(map))
		return (0);
	if (!check_char(map))
		return (0);
	if (!check_coin(map) || !check_exit(map) || !check_player(map))
		return (0);
	return (1);
}
