/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:03 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/04 15:31:23 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".libft/gnl/get_next_line.h"
# include ".libft/libft.h"
# include ".libft/printf/ft_printf.h"
# include ".minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;

}			t_data;

typedef struct s_map
{
	int		width;
	int		height;
}			t_map;

void		ft_map_init(t_data game, char *path);

#endif