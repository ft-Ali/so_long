/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:40:58 by alsiavos          #+#    #+#             */
/*   Updated: 2024/06/29 18:05:02 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Libère la mémoire allouée pour la carte et les autres ressources.
 *
 * Cette fonction libère toute la mémoire allouée pour la carte,
 * la fenêtre graphique, et la structure mlx.
 *
 * @param game Pointeur vers la structure du jeu contenant la carte
 *             et d'autres informations.
 */
void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		ft_free_split(game->map);
		game->map = NULL;
	}
}

/**
 * @brief Gère les erreurs, libère les ressources, et quitte le programme.
 *
 * Cette fonction affiche un message d'erreur, libère les ressources allouées,
 * et quitte le programme.
 *
 * @param game Pointeur vers la structure du jeu contenant la carte
 *             et d'autres informations.
 * @param msg  Message d'erreur à afficher.
 */
void	handle_error(t_map *game, const char *msg)
{
	ft_printf(RED "%s\n" RESET, msg);
	free_map(game);
	free_mlx_img(&game->img);
	close_game(game);
	exit(0);
}

void	handle_valid_message(const char *msg)
{
	ft_printf(GREEN "%s\n" RESET, msg);
}

/**
 * @brief Vérifie que l'extension du fichier de la carte est ".ber".
 *
 * Cette fonction vérifie que le fichier de la carte a une extension ".ber".
 * En cas d'erreur, elle appelle handle_error().
 *
 * @param game Pointeur vers la structure du jeu contenant la carte
 *             et d'autres informations.
 * @param file Nom du fichier de la carte.
 */
void	check_file_extension(t_map *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || !ft_strnstr(&file[len - 4], ".ber", 4))
		handle_error(game, "Map file extension is wrong (It should be .ber).");
}

/**
 * @brief Vérifie que la carte n'est pas vide.
 *
 * Cette fonction vérifie que la carte n'est pas vide.
 * En cas d'erreur, elle appelle handle_error().
 *
 * @param game Pointeur vers la structure du jeu contenant la carte
 *             et d'autres informations.
 */
void	ft_empty(t_map *game)
{
	int	i;

	i = 0;
	if (game->map[i] == NULL)
		handle_error(game, "Map is empty");
}
