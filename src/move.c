/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:08:33 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 22:58:44 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	char	next_case;

	next_case = game->map[new_y][new_x];
	if (next_case == '1')
		return ;
	if (next_case == 'E' && game->coin == 0)
	{
		ft_printf("Bravo Champion\n");
		exit (0);
	}
	if (next_case == 'C')
		game->coin--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	render_map(game);
}

int	move_handler(t_game *game, int key)
{
	if (key == 13) //haut
		move_player(game, game->player_y - 1, game->player_x);
	return (0);

}
