/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:53 by dufama            #+#    #+#             */
/*   Updated: 2025/11/10 18:59:43 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

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



#endif
