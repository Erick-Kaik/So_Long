/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:00 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/07 22:08:18 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	if (str == NULL)
		return (NULL);
	dest = malloc(ft_strlen(str) + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, str, ft_strlen(str) + 1);
	return (dest);
}
