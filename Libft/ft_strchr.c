/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:35:46 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/25 19:42:09 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (NULL);
	while (str[x] != (unsigned char)c && str[x] != '\0')
		x++;
	if (str[x] == (unsigned char)c)
		return ((char *)&str[x]);
	return (NULL);
}
