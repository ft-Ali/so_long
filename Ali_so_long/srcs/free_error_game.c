/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:40:58 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/17 13:10:22 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (game->map)
		ft_free_split(game->map);
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

void	check_file_extension(t_map *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || !ft_strnstr(&file[len - 4], ".ber", 4))
		handle_error(game, "Map file extension is wrong (It should be .ber).");
}

void	ft_empty(t_map *game)
{
	int	i;

	i = 0;
	if (game->map[i] == NULL || game->map[0][i] == '\n')
		handle_error(game, "Map is empty");
}
