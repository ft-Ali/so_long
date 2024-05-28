/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:12 by alsiavos          #+#    #+#             */
/*   Updated: 2023/11/13 18:24:23 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	unsigned int	total_size;
	char			*new;

	if (!s)
		return (NULL);
	total_size = 0;
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	s = s + start;
	while (s[total_size] && len--)
		total_size++;
	new = malloc(sizeof(char) * (total_size + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, total_size + 1);
	return (new);
}
