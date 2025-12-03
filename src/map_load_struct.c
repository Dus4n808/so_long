/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:16:07 by dufama            #+#    #+#             */
/*   Updated: 2025/12/01 18:16:14 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_height(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

static int	get_content(t_game *game, char content)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == content)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	get_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_struct(t_game *game)
{
	game->move = 0;
	game->height = get_height(game);
	game->width = ft_strlen(game->map[0]);
	game->coin = get_content(game, 'C');
	game->player = get_content(game, 'P');
	game->exit = get_content(game, 'E');
	get_player_pos(game);
	game->mlx = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_coin = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
}
