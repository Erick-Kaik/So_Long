/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:17:13 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/25 16:13:42 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			x;
	unsigned char	*temp;

	x = 0;
	temp = (unsigned char *)str;
	if (str == NULL)
		return (NULL);
	while (x < n)
	{
		if (temp[x] == (unsigned char)c)
			return ((unsigned char *)&temp[x]);
		x++;
	}
	return (NULL);
}
