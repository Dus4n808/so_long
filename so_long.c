/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:20 by dufama            #+#    #+#             */
/*   Updated: 2025/11/22 21:42:10 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	(void)game;
	ft_printf("Key hooks : %d\n", keycode);
	return (0);
}


int	main(int argc, char **argv)
{
	t_game	game;


	if (argc != 2)
	{
		ft_printf("Entrer le fichier\n");
		exit (1);
	}

	game.map = read_and_stock_map(argv[1]);
	check_shape_map(game.map);
	check_content(game.map);
	check_solvable(game.map);

	print_map(&game);


	// init_struct(map, &game);
	// //free_map(map);
	// game.mlx = mlx_init();
	// game.win = mlx_new_window(game.mlx, game.width * IMG_CUB, game.height * IMG_CUB, "CrackHead");
	// load_img(&game);
	// render_map(&game);
	// ft_printf("Position du joueur x : %d et y : %d\n", game.player_x, game.player_y);
	// mlx_key_hook(game.win, key_hook, &game);
	// mlx_loop(game.mlx);

	return (0);
}

