/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:38:52 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/12 11:59:02 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int	height;

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
void	check_map_valid(t_map *game)
{
	int i;
	int j;
	char *map_character;

	map_character = "10PEC";
	i = 0;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(map_character, game->map[i][j]))
				handle_error(game, "Map should be only composed with Floor,Wall, Player, Exit, Coins (10PEC)");
			j++;
		}
		i++;
	}
}

/*************
check s'il y a au moins 1 exit, 1 player, 1 coins et les compter
*************/