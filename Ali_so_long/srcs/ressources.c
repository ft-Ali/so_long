/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:05:23 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/29 18:04:33 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_img *img, t_map *game)
{
	img->wall_img = mlx_xpm_file_to_image(img->mlx_ptr, "img/wall.xpm",
			&game->pixel, &game->pixel);
	if (img->wall_img == NULL)
		handle_error(game, "Failed to load wall img..");
	img->floor_img = mlx_xpm_file_to_image(img->mlx_ptr, "img/floor.xpm",
			&game->pixel, &game->pixel);
	if (img->floor_img == NULL)
		handle_error(game, "Failed to load floor img..");
	img->player_img = mlx_xpm_file_to_image(img->mlx_ptr, "img/cat.xpm",
			&game->pixel, &game->pixel);
	if (img->player_img == NULL)
		handle_error(game, "Failed to load player img..");
	img->collectibles_img = mlx_xpm_file_to_image(img->mlx_ptr, "img/coins.xpm",
			&game->pixel, &game->pixel);
	if (img->collectibles_img == NULL)
		handle_error(game, "Failed to load collectibles img..");
	img->exit_img = mlx_xpm_file_to_image(img->mlx_ptr, "img/exit.xpm",
			&game->pixel, &game->pixel);
	if (img->exit_img == NULL)
		handle_error(game, "Failed to load exit img..");
}

void	draw_map(t_map *game, t_img *img)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->pixel;
			y = i * game->pixel;
			if (game->map[i][j] == WALL)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
					img->wall_img, x, y);
			if (game->map[i][j] == FLOOR)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
					img->floor_img, x, y);
			j++;
		}
		i++;
	}
}

void	draw_map_2(t_map *game, t_img *img)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->pixel;
			y = i * game->pixel;
			if (game->map[i][j] == PLAYER)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
					img->player_img, x, y);
			if (game->map[i][j] == COLLECTIBLES)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
					img->collectibles_img, x, y);
			j++;
		}
		i++;
	}
}

void	draw_map_exit(t_map *game, t_img *img)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			x = j * game->pixel;
			y = i * game->pixel;
			if (game->map[i][j] == MAP_EXIT)
			{
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
					img->exit_img, x, y);
				game->exit_x = j;
				game->exit_y = i;
			}
		}
		i++;
	}
}

void	free_mlx_img(t_img *img)
{
	if (img->collectibles_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->collectibles_img);
		img->collectibles_img = NULL;
	}
	if (img->exit_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->exit_img);
		img->exit_img = NULL;
	}
	if (img->floor_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->floor_img);
		img->floor_img = NULL;
	}
	if (img->player_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->player_img);
		img->player_img = NULL;
	}
	if (img->wall_img)
	{
		mlx_destroy_image(img->mlx_ptr, img->wall_img);
		img->wall_img = NULL;
	}
}
