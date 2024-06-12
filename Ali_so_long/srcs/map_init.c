/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/12 14:02:28 by alsiavos         ###   ########.fr       */
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
	line_tmp = get_next_line(map_fd);
	while (line_tmp != NULL)
	{
		line_map = ft_freejoin(line_map, line_tmp, ft_strlen(line_map),
				ft_strlen(line_tmp));
		free(line_tmp);
		game->height++;
		line_tmp = get_next_line(map_fd);
	}
	close(map_fd);
	game->map = ft_split(line_map, '\n');
	free(line_map);
	ft_empty(game);
}

void	initialize_and_check_map(t_map *game, char *path)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	check_file_extension(game, path);
	initialize_map(game, path);
	check_map_valid(game);
	check_game_info(game);
	check_map_rectangle(game);
	check_border_colum(game);
	print_map(game);
}
