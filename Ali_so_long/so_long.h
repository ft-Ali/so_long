/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:03 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/29 17:56:37 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".libft/gnl/get_next_line.h"
# include ".libft/libft.h"
# include ".libft/printf/ft_printf.h"
# include ".minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLES 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define PIXEL 32

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307
# define ESC2 33

typedef struct s_img
{
	void	*img_ptr;
	void	*player_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*floor_img;
	void	*wall_img;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		flood_exit;
	int		flood_collect;
	int		collectibles;
	int		exit;
	int		spawn;
	char	**map;
	int		pixel;
	int		collectibles_left;
	int		step_count;
	t_img	img;

}			t_map;

/************************************
				PARSING
*************************************/

void		game_init(t_map *game);
int			check_and_open_file(t_map *game, char *file);
void		initialize_and_check_map(t_map *game, char *path);
int			initialize_map(t_map *game, char *file);
void		check_file_extension(t_map *game, char *file);
void		check_map_valid(t_map *game);
void		check_game_info(t_map *game);
void		check_game_info_utils(t_map *game, int exit, int collectibles,
				int spawn);
void		check_map_rectangle(t_map *game);
void		check_border_colum(t_map *game);
int			check_map_height(char **map);

void		flood_fill(t_map *game, char **map, int x, int y);
void		find_player(t_map *game);
void		flood_fill_result(t_map *map_cpy);
char		**ft_cpy(char **cpy, int height);
void		handle_valid_message(const char *msg);

/************************************
				ERROR & FREE
*************************************/

void		ft_empty(t_map *game);
void		handle_valid_message(const char *msg);
void		handle_error(t_map *game, const char *msg);
void		free_map(t_map *game);
void		free_map_cpy(char **cpy, int height);

int			close_window(void *param);
int			close_game(t_map *game);

void		print_map(t_map *game);

/************************************
				IMG
*************************************/

void		init_img(t_img *img, t_map *game);
void		draw_map(t_map *game, t_img *img);
void		draw_map_2(t_map *game, t_img *img);
void		draw_map_exit(t_map *game, t_img *img);
void		draw_all_maps(t_map *game, t_img *img);
void		free_mlx_img(t_img *img);

int			handle_key(int key, t_map *game);
void		move_player(t_map *game, int new_x, int new_y);
void		collect_item(t_map *game, int x, int y);

#endif