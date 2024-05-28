/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:33 by alsiavos          #+#    #+#             */
/*   Updated: 2023/11/16 13:26:12 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
/*
Vérification si les zones de mémoire source et destination sont les mêmes 
: La fonction commence par
 vérifier si les zones de mémoire source et destination sont identiques.
  Si c'est le cas,
cela signifie qu'il n'y a rien à copier,
et elle retourne directement le pointeur vers la destination.

Copie de droite à gauche si les zones se chevauchent
 et la source est avant la destination
 : Si les zones se chevauchent et la zone source est 
 située avant la zone destination dans la mémoire,
	la fonction copie de droite à gauche pour éviter 
	d'écraser des données avant leur copie.

Copie de gauche à droite si les zones se chevauchent 
et la destination est avant la source
: Si la zone destination est située avant la zone source,
la fonction effectue une copie normale de gauche à droite.

Retour du pointeur vers la zone de destination : Enfin,
	la fonction retourne un pointeur vers la zone de destination.
	
*/