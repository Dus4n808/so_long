/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:34 by dufama            #+#    #+#             */
/*   Updated: 2025/12/02 18:23:43 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_game(t_game *game)
{
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
