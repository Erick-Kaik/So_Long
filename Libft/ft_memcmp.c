/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:42:50 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/25 19:31:05 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			x;
	size_t			value;
	unsigned char	*temp1;
	unsigned char	*temp2;

	x = 0;
	value = 0;
	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (x < n)
	{
		if (temp1[x] != temp2[x])
		{
			value = temp1[x] - temp2[x];
			break ;
		}
		x++;
	}
	return (value);
}
