/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:03 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/27 18:39:17 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".libft/gnl/get_next_line.h"
# include ".libft/libft.h"
# include ".libft/printf/ft_printf.h"
# include ".minilibx-linux/mlx.h"
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

typedef struct s_img
{
	void	*img_ptr;
	void	*tex_player;
	void	*tex_collectibles;
	void	*tex_exit;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		flood_exit;
	int		flood_collect;
	int		collectibles;
	int		exit;
	int		spawn;
	char	**map;
	int		pixel;

	t_img	data;

}			t_map;

/************************************
				PARSING
*************************************/

void		game_init(t_map *game);
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

void		print_map(t_map *game);
void		print_cpy(char **cpy);

/************************************
				IMG
*************************************/
void		init_texture(t_img *img);
void	init_img(t_map *game);
void		draw_map(t_map *game);
#endif