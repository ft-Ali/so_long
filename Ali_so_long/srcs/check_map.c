/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:38:52 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/26 13:13:42 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Vérifie si la carte est rectangulaire.
 *
 * Cette fonction vérifie que chaque,
 * ligne de la carte a la même longueur
 * ce qui garantit que la carte est bien rectangulaire.
 *
 * @param game Pointeur vers la structure du jeu contenant.
 * la carte et d'autres informations
 */

void	check_map_rectangle(t_map *game)
{
	int	i;
	int	width;
	int	current_width;

	i = 1;
	width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		current_width = ft_strlen(game->map[i]);
		if (current_width != width)
			handle_error(game, "Map is not rectangular");
		i++;
	}
}

/**
 * @brief Vérifie si la carte est bien entourée de murs.
 *
 * Cette fonction vérifie que la première et la dernière ligne, ainsi que
 * la première et la dernière colonne de la carte
 * sont entièrement composées de murs.
 *
 * @param game Pointeur vers la structure du jeu contenant
 * la carte et d'autres informations.
 */
void	check_border_colum(t_map *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(game->map[0]);
	height = game->height;
	if (!game->map[i] || game->height == 1)
		handle_error(game, "Map is not initialized");
	while (i < width)
	{
		if (game->map[0][i] != WALL || (game->map[height - 1][i] != WALL))
			handle_error(game, "Map do not enclosed Wall");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != WALL || (game->map[i][width - 1] != WALL))
			handle_error(game, "Map do not enclosed Border Wall");
		i++;
	}
}

/**
 * @brief Vérifie si les caractères de la carte sont valides.
 *
 * Cette fonction vérifie que la carte ne contient que
 * des caractères valides
 * (1, 0, P, E, C).
 *
 * @param game Pointeur vers la structure du jeu
 * contenant la carte et d'autres informations.
 */
void	check_map_valid(t_map *game)
{
	int		i;
	int		j;
	char	*map_character;

	map_character = "10PEC";
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(map_character, game->map[i][j]))
				handle_error(game, "Map should be only composed with(10PEC)");
			j++;
		}
		i++;
	}
}

/**
 * @brief Vérifie les contraintes du jeu.
 *
 * Cette fonction vérifie que la carte contient exactement une sortie, au moins
 * un objet à collecter et un seul point de départ.
 *
 * @param game Pointeur vers la structure du jeu contenant
 * la carte et d'autres informations.
 * @param exit Nombre de sorties trouvées sur la carte.
 * @param collectibles Nombre d'objets à collecter trouvés sur la carte.
 * @param spawn Nombre de points de départ trouvés sur la carte.
 */
void	check_game_info_utils(t_map *game, int exit, int collectibles,
		int spawn)
{
	if (exit != 1)
		handle_error(game, "should have only one exit");
	if (spawn != 1)
		handle_error(game, "should have only one spawn");
	if (collectibles < 1)
		handle_error(game, "should be at least one collectibles");
}

/**
 * @brief Vérifie les informations du jeu.
 *
 * Cette fonction compte combien d'objets à collecter,
 * de points de départ et de sorties
 * se trouvent sur la carte.
 *
 * @param game Pointeur vers la structure du jeu
 * contenant la carte et d'autres informations.
 */
void	check_game_info(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == COLLECTIBLES)
				game->collectibles++;
			else if (game->map[i][j] == MAP_EXIT)
				game->exit++;
			else if (game->map[i][j] == PLAYER)
				game->spawn++;
		}
		i++;
	}
	check_game_info_utils(game, game->exit, game->collectibles, game->spawn);
}
