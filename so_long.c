/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:20 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 12:07:19 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	check_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long (map filname)\n");
		exit (1);
	}
	game.map = read_and_stock_map(argv[1]);
	check_shape_map(game.map);
	check_content(game.map);
	check_solvable(game.map);
	print_map(&game);
	init_struct(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * IMG_CUB,
			game.height * IMG_CUB, "Coucou");
	load_img(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	clean_game(&game);
	return (0);
}
