/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:48 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/24 17:18:20 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Implémente l'algorithme de remplissage par inondation pour vérifier
 *        l'accessibilité des éléments sur la carte.
 *
 * Cette fonction utilise la récursivité pour parcourir la carte depuis une
 * position donnée et marque les tuiles visitées. Elle compte les objets
 * "MAP_EXIT" et "COLLECTIBLES" rencontrés.
 *
 * @param game Pointeur vers la structure du jeu contenant les informations
 *             sur la carte.
 * @param map  Copie de la carte sur laquelle effectuer le flood fill.
 * @param x    Position x (colonne) de départ.
 * @param y    Position y (ligne) de départ.
 */
void	flood_fill(t_map *game, char **map, int x, int y)
{
	if (map[y][x] == WALL)
		return ;
	if (map[y][x] == MAP_EXIT)
		game->flood_exit++;
	else if (map[y][x] == COLLECTIBLES)
		game->flood_collect++;
	map[y][x] = WALL;
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

/**
 * @brief Crée une copie de la carte.
 *
 * Cette fonction alloue de la mémoire pour une nouvelle carte et copie
 * chaque ligne de la carte originale dans la nouvelle carte.
 *
 * @param cpy    La carte originale à copier.
 * @param height La hauteur de la carte original.
 * @return       Un pointeur vers la nouvelle copie de la carte.
 */
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

/**
 * @brief Libère la mémoire allouée pour une copie de la carte.
 *
 * Cette fonction libère chaque ligne de la copie de la carte, puis libère
 * le tableau de pointeurs.
 *
 * @param cpy    La copie de la carte à libérer.
 * @param height La hauteur de la carte.
 */
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
}

/**
 * @brief Trouve la position du joueur sur la carte et initialise le flood fill.
 *
 * Cette fonction parcourt la carte pour trouver la position initiale du joueur,
 * puis appelle la fonction flood_fill à partir de cette position.
 *
 * @param game Pointeur vers la structure du jeu contenant les informations
 *             sur la carte.
 */
void	find_player(t_map *game)
{
	char	**map_cpy;
	int		i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_y = i;
				game->player_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	map_cpy = ft_cpy(game->map, game->height);
	flood_fill(game, map_cpy, game->player_x, game->player_y);
	free_map_cpy(map_cpy, game->height);
}

/**
 * @brief Vérifie les résultats du flood fill et affiche un message approprié.
 *
 * Cette fonction compare les objets collectés et la sortie trouvée avec
 * les valeurs attendues et affiche un message de validation ou une erreur.
 *
 * @param game Pointeur vers la structure du jeu contenant les informations
 *             sur la carte.
 */
void	flood_fill_result(t_map *game)
{
	if (game->collectibles == game->flood_collect
		&& game->exit == game->flood_exit)
		handle_valid_message("All collectibles collected and exit reachable");
	else
		handle_error(game,
			"Not All collectibles collected or exit not reachable");
}
