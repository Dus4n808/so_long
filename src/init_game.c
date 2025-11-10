/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:37 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 21:59:28 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("\n----- MAP CONTENT -----\n");
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	ft_printf("-----------------------\n");
}

void	load_img(t_game *game)
{
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "assets/coin1.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &game->img_width, &game->img_height);
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

void	init_struct(char **map, t_game *game)
{
	game->map = map;
	game->height = get_height(game);
	game->width = ft_strlen(game->map[0]);
	game->coin = get_content(game, 'C');
	game->player = get_content(game, 'P');
	game->exit = get_content(game, 'E');
	get_player_pos(game);
	print_map(game);
}
