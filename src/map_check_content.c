/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:37:45 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 11:00:21 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_char(char **map)
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
				error_msg_and_free("Invalid char\n", map);
			j++;
		}
		i++;
	}
}

static void	check_player(char **map)
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
		error_msg_and_free("Invalid player\n", map);
}

static void	check_coin(char **map)
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
		error_msg_and_free("Invalid coin\n", map);
}

static void	check_exit(char **map)
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
		error_msg_and_free("Invalid exit\n", map);
}

void	check_content(char **map)
{
	check_char(map);
	check_coin(map);
	check_exit(map);
	check_player(map);
}
