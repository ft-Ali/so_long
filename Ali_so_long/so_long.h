/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:03 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/12 15:52:43 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".libft/gnl/get_next_line.h"
# include ".libft/libft.h"
# include ".libft/printf/ft_printf.h"
# include ".minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLES 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/* typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

}			t_data; */

typedef struct s_map
{
	int		width;
	int		height;
	int		x;
	int		y;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;

}			t_map;

void		initialize_map(t_map *game, char *file);
void		initialize_and_check_map(t_map *game, char *path);
void		print_map(t_map *game);
void		check_map_rectangle(t_map *game);
void		free_map(t_map *game);
void		check_border_colum(t_map *game);
void		ft_empty(t_map *game);
void		handle_valid_message(const char *msg);
void		handle_error(t_map *game, const char *msg);
void		check_file_extension(t_map *game, char *file);
void		check_map_valid(t_map *game);
void		check_game_info(t_map *game);
void		check_game_info_utils(t_map *game, int exit, int collectibles,
				int spawn);

#endif