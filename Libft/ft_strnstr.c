/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:37:42 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/25 21:26:57 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (str == NULL || find == NULL || size < ft_strlen(find))
		return (NULL);
	if (find[x] == '\0')
	{
		return ((char *)str);
	}
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == find[y] && str[x + y] != '\0' && (x + y) < size)
		{
			if (find[y + 1] == '\0')
				return ((char *)&str[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}
