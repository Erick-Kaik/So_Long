/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 01:51:02 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/27 00:56:13 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*str;
	unsigned char	*temp;

	x = 0;
	str = (unsigned char *)src;
	temp = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (n != 0)
	{
		while (x < n)
		{
			temp[x] = str[x];
			x++;
		}
	}
	return (temp);
}
