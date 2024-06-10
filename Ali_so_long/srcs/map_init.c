/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/10 15:09:22 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_map(t_map *game, char *file)
{
	int		map_fd;
	char	*line_map;
	char	*line_tmp;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
		handle_error(game, "Map does not exist");
	line_map = ft_strdup("");
	while ((line_tmp = get_next_line(map_fd)) != NULL)
	{
		line_map = ft_freejoin(line_map, line_tmp, ft_strlen(line_map),
				ft_strlen(line_tmp));
		free(line_tmp);
		game->height++;
	}
	close(map_fd);
	game->map = ft_split(line_map, '\n');
	free(line_map);
	ft_empty(game);
}

void	ft_empty(t_map *game)
{
	int	i;

	i = 0;
	if (game->map[i] == NULL)
		handle_error(game, "Map is empty");
}

void	check_map_rectangle(t_map *game)
{
	int	i;
	int	width;
	int	current_width;

	i = 1;
	if (!game->map || game->height == 0)
		return ;
	width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		current_width = ft_strlen(game->map[i]);
		if (current_width != width)
			handle_error(game, "Map is not rectangular");
		i++;
	}
}

void	check_border_colum(t_map *game)
{
	int	i;
	int	width;
	int height;

	i = 0;
	width = ft_strlen(game->map[0]);
	height = game->height;
	if (!game->map[i] || game->height == 1)
		handle_error(game, "Map is not initialized");
	while (i < width)
	{
		if (game->map[0][i] != WALL || (game->map[height - 1][i] != WALL))
			handle_error(game, "Map do not enclosed Wall");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != WALL || (game->map[i][width - 1] != WALL))
			handle_error(game, "Map do not enclosed Border Wall");
		i++;
	}
}

void	initialize_and_check_map(t_map *game, char *path)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	initialize_map(game, path);
	check_map_rectangle(game);
	check_border_colum(game);
	print_map(game);
}
