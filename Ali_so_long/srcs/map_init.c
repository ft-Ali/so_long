/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/05 17:55:53 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_init(t_map *game, char *file)
{
	int		map_fd;
	char	*line_map;
	char	*line_tmp;

	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
	{
		ft_printf(RED "Map does not exist\n");
		exit(0);
	}
	line_map = ft_strdup("");
	game->height = 0;
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
}

void	print_map(t_map *game)
{
	int i = 0;
	if (!game->map)
	{
		ft_printf("Map is not initialized\n");
		return ;
	}
	ft_printf("Map:\n");
	while(game->map[i])
		ft_printf("%s\n", game->map[i++]);
	
}

void	ft_map_malloc(t_map *game, char *path)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	ft_map_init(game, path);
	print_map(game);
}
