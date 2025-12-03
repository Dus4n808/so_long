/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:08:33 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 12:10:00 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_next_case(t_game *game, char next_case)
{
	if (next_case == '1')
		ft_printf("It's a Wall !\n");
	else if (next_case == 'C')
	{
		ft_printf("Yummy !\n");
		game->coin--;
		ft_printf("Movements : %d\n", game->move);
	}
	else if (next_case == 'E' && game->coin == 0)
	{
		ft_printf("Champion !\n");
		clean_game(game);
		exit (1);
	}
	else if (next_case == 'E' && game->coin != 0)
	{
		ft_printf("You are blind !\n");
	}
	else
		ft_printf("Movements : %d\n", game->move);
}

static void	move_player(t_game *game, int new_y, int new_x)
{
	char	next_case;

	next_case = game->map[new_y][new_x];
	check_next_case(game, next_case);
	if (next_case == '1')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	if (next_case == 'E' && game->coin != 0)
		return ;
	if (next_case != 'E')
		game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->move++;
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

static int	move_handler(t_game *game, int key)
{
	if (key == KEY_W || key == KEY_UP)
		move_player(game, game->player_y - 1, game->player_x);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->player_y + 1, game->player_x);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, game->player_y, game->player_x - 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, game->player_y, game->player_x + 1);
	if (key == KEY_ESC)
	{
		clean_game(game);
		exit (1);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	move_handler(game, keycode);
	return (0);
}
