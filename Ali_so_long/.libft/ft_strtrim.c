/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:45 by alsiavos          #+#    #+#             */
/*   Updated: 2023/11/15 09:54:44 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const *set, int c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dest;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && check_set(set, s1[start]))
		start++;
	while (check_set(set, s1[end - 1]) && end > start)
		end--;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1 + start, end - start + 1);
	return (dest);
}
