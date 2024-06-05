/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/05 18:31:34 by alsiavos         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (!game->map)
	{
		ft_printf("Map is not initialized\n");
		return ;
	}
	ft_printf("Map:\n");
	while (game->map[i])
		ft_printf("%s\n", game->map[i++]);
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
		{
			ft_printf(RED "Map is not rectangular\n");
			exit(0);
		}
		i++;
	}
	ft_printf(GREEN "Map is valid\n");
}

void	initialize_and_check_map(t_map *game, char *path)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	initialize_map(game, path);
	check_map_rectangle(game);
	print_map(game);
}
