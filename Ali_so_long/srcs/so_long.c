/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/29 18:11:12 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_display(t_map *game)
{
	mlx_destroy_display(game->img.mlx_ptr);
	free(game->img.mlx_ptr);
	free_map(game);
	exit(0);
}

int	close_game(t_map *game)
{
	if (game->img.mlx_ptr != NULL)
		mlx_destroy_window(game->img.mlx_ptr, game->img.win_ptr);
	free_mlx_img(&game->img);
	if (game->img.win_ptr != NULL)
		close_display(game);
	free_map(game);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	init_struct(t_map *game)
{
	game->img.mlx_ptr = mlx_init();
	game->img.win_ptr = mlx_new_window(game->img.mlx_ptr, game->width
			* game->pixel, game->height * game->pixel, "next project pls");
	if (!game->img.win_ptr)
	{
		ft_printf(RED "Mlx failed to open");
		free_map(game);
		free_mlx_img(&game->img);
		return ;
	}
	init_img(&game->img, game);
	draw_all_maps(game, &game->img);
	game->step_count = 0;
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
	init_struct(&game);
	mlx_key_hook(game.img.win_ptr, handle_key, &game);
	mlx_hook(game.img.win_ptr, DestroyNotify, 0, &close_game, &game);
	mlx_loop(game.img.mlx_ptr);
	close_game(&game);
	free_map(&game);
}
