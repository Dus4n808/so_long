/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:34 by dufama            #+#    #+#             */
/*   Updated: 2025/11/23 17:41:01 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	clean_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_coin);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_map(game->map);
}

void	error_msg_and_free(char *msg, char **map)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	free_map(map);
	exit(1);
}

void	print_map(t_game *game)
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
