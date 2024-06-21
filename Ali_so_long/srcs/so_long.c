/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/20 15:11:35 by alsiavos         ###   ########.fr       */
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

void	print_cpy(char **cpy)
{
	int	i;

	i = 0;
	if (!cpy)
	{
		ft_printf("Rien dedans donc exit 0");
		exit(0);
	}
	while (cpy[i])
	{
		printf(CYAN "%s\n" RESET, cpy[i]);
		i++;
	}
}
void	close_display(t_map *game)
{
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game);
	exit(0);
}
int	close_game(t_map *game)
{
	// free_img(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	close_display(game);
	return (0);
}

int    close_window(void *param)
{
    (void)param;
	exit(0);
    return (0);
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
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "so_long");
	mlx_hook(game.win_ptr, 17, 0, close_window, NULL);
	if (!game.win_ptr)
	{
		ft_printf(RED "Mlx failed to open");
		// free_map(&game);
		return (0);
	}
	mlx_loop(game.mlx_ptr);
	close_game(&game);
	free_map(&game);
}
