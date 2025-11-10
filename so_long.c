/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:20 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 19:34:58 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"


int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;


	if (argc != 2)
	{
		ft_printf("Entrer le fichier\n");
		exit (1);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		ft_printf("Error\nFichier non conforme\n");
		exit(1);
	}

	if (!is_valid_map(map))
	{
		free_map(map);
		exit(1);
	}

	init_struct(map, &game);
	//free_map(map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "CrackHead");
	load_img(&game);
	render_map(&game);
	ft_printf("Position du joueur x : %d et y : %d\n", game.player_x, game.player_y);
	mlx_loop(game.mlx);

	return (0);
}

