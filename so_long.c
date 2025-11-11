/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:20 by dufama            #+#    #+#             */
/*   Updated: 2025/11/11 18:23:35 by dufama           ###   ########.fr       */
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
	char	**map;
	t_game	game;


	if (argc != 2)
	{
		ft_printf("Entrer le fichier\n");
		exit (1);
	}
	if (!check_extension(argv[1]))
	{
		ft_printf("Entrer le bon format de fichier(.ber)\n");
		exit(1);
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
	game.win = mlx_new_window(game.mlx, game.width * IMG_CUB, game.height * IMG_CUB, "CrackHead");
	load_img(&game);
	render_map(&game);
	ft_printf("Position du joueur x : %d et y : %d\n", game.player_x, game.player_y);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);

	return (0);
}

