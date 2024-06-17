/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:48 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/17 16:11:29 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_cpy(char **cpy, int height)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (i < height)
	{
		new[i] = ft_strdup(cpy[i]);
		if (!new[i])
			free_map_cpy(new, height);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	free_map_cpy(char **cpy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(cpy[i]);
		i++;
	}
	free(cpy);
	ft_printf("bien free y'a plus rien\n" RESET);
}

void	flood_fill(char **map, int x, int y)
{
	if()
}