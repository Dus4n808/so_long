/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:53 by dufama            #+#    #+#             */
/*   Updated: 2025/11/23 18:39:54 by dufama           ###   ########.fr       */
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
} t_game ;
// a supprimer apres
void	print_map(t_game *game);
// Read et check
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
