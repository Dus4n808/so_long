/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:53 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 11:30:54 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
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
	int		move;

	void	*mlx;
	void	*win;

	void	*img_wall;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	void	*img_floor;

	int		img_width;
	int		img_height;
}	t_game;
//print
void	print_map(t_game *game);
// Read et check
int		check_extension(char *filename);
char	**read_and_stock_map(char *filename);
void	check_shape_map(char **map);
void	check_content(char **map);
void	check_solvable(char **map);
//Utile
void	clean_game(t_game *game);
void	free_map(char **map);
void	error_msg_and_free(char *msg, char **map);

//init struct
void	init_struct(t_game *game);
//init graphic
void	load_img(t_game *game);
void	render_map(t_game *game);
//Move
int		key_hook(int keycode, t_game *game);

#endif
