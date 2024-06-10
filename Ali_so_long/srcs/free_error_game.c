/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:40:58 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/10 14:41:08 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (game->map)
		ft_free_split(game->map);
	// while(game->map[i])
	// 	free(game->map[i++]);
	// free(game->map);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}

void	handle_error(t_map *game, const char *msg)
{
	ft_printf(RED "%s\n" RESET, msg);
	free_map(game);
	exit(0);
}

void	handle_valid_message(const char *msg)
{
	ft_printf(GREEN "%s\n" RESET, msg);
}

void	print_map(t_map *game)
{
	int	i;

	i = 0;
	if (!game->map[i])
		handle_error(game, "Map is not initialized");
	ft_printf(GREEN "Map is valid\n" RESET);
	ft_printf("Map:\n");
	while (game->map[i])
		ft_printf(GREEN "%s\n" RESET, game->map[i++]);
}