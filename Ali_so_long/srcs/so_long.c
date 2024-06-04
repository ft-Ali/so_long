/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:03:16 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/04 15:13:28 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	t_data game;
	game.fd = -1;
	ft_map_init(game, argv[1]);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "so_long");
	mlx_loop(game.mlx_ptr);
	return (0);
}