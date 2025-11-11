/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:53 by dufama            #+#    #+#             */
/*   Updated: 2025/11/11 09:05:37 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
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

// Read et check
char	**read_map(char *file);
int		is_good_wall_and_shape(char **map);
int		is_valid_map(char **map);
int		check_extension(char *filename);
//Utile
void	free_game(t_game *game);
void	free_map(char **map);
//Get info
int		get_height(t_game *game);
int		get_content(t_game *game, char content);
void	get_player_pos(t_game *game);
//init
void	init_struct(char **map, t_game *game);
void	load_img(t_game *game);
void	render_map(t_game *game);
//Move
int	move_handler(t_game *game, int key);
void	move_player(t_game *game, int new_y, int new_x);


#endif
