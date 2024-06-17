/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/17 12:57:38 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
	{
		ft_printf(RED "Usage: %s <map_dir>/<map_file>\n" RESET, argv[0]);
		return (0);
	}
	initialize_and_check_map(&game, argv[1]);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 600, "so_long");
	if (!game.win_ptr)
	{
		ft_printf(RED "Mlx failed to open");
		free_map(&game);
		return (0);
	}
	mlx_loop(game.mlx_ptr);
	free_map(&game);
}
