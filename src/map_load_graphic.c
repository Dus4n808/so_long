/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_graphic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:37 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 11:00:56 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*safe_load(t_game *game, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path,
			&game->img_width, &game->img_height);
	if (!img)
	{
		ft_printf("Error Map\n");
		clean_game(game);
		exit(1);
	}
	return (img);
}

void	load_img(t_game *game)
{
	game->img_coin = safe_load(game, "assets/coin1.xpm");
	game->img_wall = safe_load(game, "assets/wall1.xpm");
	game->img_floor = safe_load(game, "assets/floor1.xpm");
	game->img_exit = safe_load(game, "assets/exit1.xpm");
	game->img_player = safe_load(game, "assets/player1.xpm");
}

static void	put(t_game *game, int x, int y, char tile)
{
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_coin, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x, y);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put(game, x * IMG_CUB, y * IMG_CUB, game->map[y][x]);
			x++;
		}
		y++;
	}
}
