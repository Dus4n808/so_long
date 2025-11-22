/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:53 by dufama            #+#    #+#             */
/*   Updated: 2025/11/22 21:35:22 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# ifdef __APPLE__
# include "../mlx/mlx.h"
# else
# include "../mlx_linux/mlx.h"
# endif
# define IMG_CUB 64

typedef struct s_game
{
	char	**map;
	int		coin;
	int		player;
	int		exit;
	int		height;
	int		width;
	int		player_x;
	int		player_y;

	void	*mlx;
	void	*win;

	void	*img_wall;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	void	*img_floor;

	int		img_width;
	int		img_height;
} t_game ;
// a supprimer apres
void	print_map(t_game *game);
// Read et check
char	**read_and_stock_map(char *filename);
void	check_shape_map(char **map);
void	check_content(char **map);
void	check_solvable(char **map);
//Utile
void	free_game(t_game *game);
void	free_map(char **map);
void	error_msg_and_free(char *msg, char **map);
//Get info
int		get_height(t_game *game);
int		get_content(t_game *game, char content);
void	get_player_pos(t_game *game);
//init
void	init_struct(char **map, t_game *game);
void	load_img(t_game *game);
void	render_map(t_game *game);
//Move
int		move_handler(t_game *game, int key);
void	move_player(t_game *game, int new_y, int new_x);
//test
int	key_hook(int keycode, t_game *game);


#endif
