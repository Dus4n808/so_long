/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:34 by dufama            #+#    #+#             */
/*   Updated: 2025/11/22 21:09:14 by dufama           ###   ########.fr       */
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

void	free_game(t_game *game)
{
	if (game->map)
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
