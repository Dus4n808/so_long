/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_graphic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:37 by dufama            #+#    #+#             */
/*   Updated: 2025/11/23 20:07:50 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*safe_load(t_game *game, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->img_width, &game->img_height);
	if (!img)
	{
		ft_printf("Erreur dans le chargement des images\n");
		clean_game(game);
		exit(1);
	}
	return (img);
}

void	load_img(t_game *game)
{
	game->img_coin = safe_load(game, "assets/coin.xpm");
	game->img_wall = safe_load(game, "assets/wall.xpm");
	game->img_floor = safe_load(game, "assets/floor.xpm");
	game->img_exit = safe_load(game, "assets/exit.xpm");
	game->img_player = safe_load(game, "assets/player.xpm");
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
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * IMG_CUB, y * IMG_CUB);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * IMG_CUB, y * IMG_CUB);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * IMG_CUB, y * IMG_CUB);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * IMG_CUB, y * IMG_CUB);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * IMG_CUB, y * IMG_CUB);
			x++;
		}
		y++;
	}
}
