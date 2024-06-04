/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/04 15:32:42 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	ft_map_init(t_data game, char *path)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	game.fd = fd;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
}