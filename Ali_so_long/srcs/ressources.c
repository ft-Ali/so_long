/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:05:23 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/27 18:40:32 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_texture(t_img *img)
{
	// ft_bzero(img,sizeof(t_img));
	// img->pixel = PIXEL;
	img->img_ptr = NULL;
	img->tex_player = NULL;
	img->tex_collectibles = NULL;
	img->tex_exit = NULL;
	img->mlx_ptr = NULL;
	img->win_ptr = NULL;
}

void	init_img(t_map *game)
{
	game->data.tex_collectibles = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"pokeball.xpm", &game->pixel, &game->pixel);
	if (game->data.tex_collectibles == NULL)
		printf("ERROR \n");
	if(game->data.mlx_ptr == NULL)
		printf("ERROR MLX\n");
	// printf("Error pixel %d\n", img->pixel);
}

void	draw_map(t_map *game)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = 0;
	printf(" width %d\n", game->width);
	printf(" width %d\n", game->height);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			x = j * game->pixel;
			y = i * game->pixel;
			// printf("pixel %d\n", game->pixel);
			printf("x %d\n", x);
			printf("y %d\n", y);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
					game->data.tex_collectibles, x, y);
			j++;
		}
		i++;
	}
}