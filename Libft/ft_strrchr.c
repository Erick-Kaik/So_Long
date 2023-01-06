/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:09 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/27 14:51:57 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (NULL);
	while (str[x] != '\0')
		x++;
	if (str[x] == '\0')
	{
		while (str[x] != (unsigned char)c && x >= 0)
		{
			if (x == 0)
				break ;
			else
			x--;
		}
		if (str[x] == (unsigned char)c)
			return ((char *)&str[x]);
	}
	return (NULL);
}
