/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:02:31 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/29 17:26:22 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == MAP_EXIT)
	{
		if (game->collectibles_left == 0)
		{
			ft_printf(GREEN "Congrats LEVEL COMPLETE!!!\n" RESET);
			close_game(game);
		}
		else
			game->map[new_y][new_x] = FLOOR;
	}
	else if (game->map[new_y][new_x] == WALL)
		return ;
	else if (game->map[new_y][new_x] == COLLECTIBLES)
		collect_item(game, new_x, new_y);
	game->map[game->player_y][game->player_x] = FLOOR;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->exit_y][game->exit_x] = MAP_EXIT;
	game->map[game->player_y][game->player_x] = PLAYER;
	game->step_count++;
	ft_printf(CYAN "Steps: %d\n" RESET, game->step_count);
	draw_all_maps(game, &game->img);
}

void	collect_item(t_map *game, int x, int y)
{
	if (game->map[y][x] == COLLECTIBLES)
	{
		game->map[y][x] = FLOOR;
		game->collectibles_left--;
	}
}

int	handle_key(int key, t_map *game)
{
	if (key == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	else if (key == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	if (key == XK_Escape)
		close_game(game);
	return (0);
}

void	draw_all_maps(t_map *game, t_img *img)
{
	draw_map(game, img);
	draw_map_2(game, img);
	draw_map_exit(game, img);
}

int	check_and_open_file(t_map *game, char *file)
{
	int	map_fd;

	map_fd = open(file, O_DIRECTORY);
	if (map_fd != -1)
	{
		close(map_fd);
		handle_error(game, "Error: directory or map does not exist");
	}
	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
	{
		close(map_fd);
		handle_error(game, "Map does not exist");
	}
	return (map_fd);
}
