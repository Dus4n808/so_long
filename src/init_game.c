/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:37 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 19:29:40 by dufama           ###   ########.fr       */
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
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "assets/coin.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &game->img_width, &game->img_height);
	if (!game->img_coin)
	{
		ft_printf("Impossible de charger l'image\n");
		exit(1);
	}
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
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * 64, y * 64);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
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
