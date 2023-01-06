/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:31:57 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/04 00:25:58 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*str;
	unsigned char	*temp;

	x = 0;
	str = (unsigned char *)src;
	temp = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (str < temp)
	{
		while (n > x)
		{
			n--;
			temp[n] = str[n];
		}
		return (temp);
	}
	while (n > x)
	{
		temp[x] = str[x];
		x++;
	}
	return (temp);
}
