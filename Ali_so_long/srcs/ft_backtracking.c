/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:48 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/21 15:01:43 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map *game, char **map, int x, int y)
{
	if (map[y][x] == WALL)
		return ;
	if (map[y][x] == MAP_EXIT)
		game->flood_exit++;
	else if (map[y][x] == COLLECTIBLES)
		game->flood_collect++;
	map[y][x] = WALL;
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

char	**ft_cpy(char **cpy, int height)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (i < height)
	{
		new[i] = ft_strdup(cpy[i]);
		if (!new[i])
			free_map_cpy(new, height);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	free_map_cpy(char **cpy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(cpy[i]);
		i++;
	}
	free(cpy);
	ft_printf("bien free y'a plus rien\n" RESET);
}

void	find_player(t_map *game)
{
	char	**map_cpy;
	int		i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_y = i;
				game->player_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	map_cpy = ft_cpy(game->map, game->height);
	flood_fill(game, map_cpy, game->player_x, game->player_y);
	print_map(game);
	ft_printf("\n");
	print_cpy(map_cpy);
	free_map_cpy(map_cpy, game->height);
	ft_printf(RED "Found exit : %d\n" RESET, game->flood_exit);
	ft_printf(YELLOW "Visited collectibles: %d\n" RESET, game->flood_collect);
	ft_printf(YELLOW "Collectibles in total %d\n" RESET, game->collectibles);
	ft_printf(PURPLE "Pos player \n x %d\n y %d\n" RESET, game->player_x, game->player_y);
	
	
}
void flood_fill_result(t_map *game)
{
	if(game->collectibles == game->flood_collect && game->exit ==  game->flood_exit)
		handle_valid_message("All collectibles collected and exit reachable");
	else 
		handle_error(game, "Not All collectibles collected or exit not reachable");
}
	