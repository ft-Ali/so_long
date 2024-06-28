/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:20 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/28 13:49:30 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Initialise la carte de jeu en lisant le fichier de la carte.
 *
 * Cette fonction ouvre le fichier de la carte, lit son contenu et remplit
 * la structure de jeu avec les informations de la carte. Elle gère également
 * les erreurs liées à l'ouverture du fichier.
 *
 * @param game Pointeur vers la structure du jeu contenant l
 * es informations sur la carte.
 * @param file Nom du fichier de la carte.
 */
int	initialize_map(t_map *game, char *file)
{
	int		map_fd;
	char	*line_map;
	char	*line_tmp;

	map_fd = open(file, O_DIRECTORY);
	if (map_fd != -1)
		(handle_error(game, "Error directory OR Map does not exist"),
			close(map_fd));
	map_fd = open(file, O_RDONLY);
	if (map_fd == -1)
		handle_error(game, "Map does not exist");
	line_tmp = get_next_line(map_fd);
	line_map = ft_strdup("");
	while (line_tmp != NULL)
	{
		line_map = ft_freejoin(line_map, line_tmp, ft_strlen(line_map),
				ft_strlen(line_tmp));
		free(line_tmp);
		line_tmp = get_next_line(map_fd);
	}
	game->map = ft_split(line_map, '\n');
	game->height = check_map_height(game->map);
	return (free(line_map), ft_empty(game), close(map_fd), 0);
}

int	check_map_height(char **map)
{
	int	k;

	k = 0;
	while (map[k])
		k++;
	return (k);
}

/**
 * @brief Initialise les variables du jeu.
 *
 * Cette fonction initialise toutes les variables de la structure du jeu
 * à leurs valeurs par défaut.
 *
 * @param game Pointeur vers la structure du jeu contenant
 * les informations sur la carte.
 */
void	game_init(t_map *game)
{
	ft_bzero(game, sizeof(t_map));
	game->pixel = PIXEL;
}

/**
 * @brief Initialise et vérifie la carte de jeu.
 *
 * Cette fonction appelle les fonctions d'initialisation et de vérification
 * pour s'assurer que la carte de jeu est correctement configurée et valide.
 *
 * @param game Pointeur vers la structure du jeu contenant
 * les informations sur la carte.
 * @param path Chemin vers le fichier de la carte.
 */
void	initialize_and_check_map(t_map *game, char *path)
{
	game_init(game);
	initialize_map(game, path);
	check_file_extension(game, path);
	check_map_valid(game);
	check_game_info(game);
	check_map_rectangle(game);
	check_border_colum(game);
	find_player(game);
	flood_fill_result(game);
}

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
