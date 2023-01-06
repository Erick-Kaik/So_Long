/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:55:02 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/27 01:34:26 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	value;
	void	*dest;

	value = nitems * size;
	dest = malloc(value);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, '\0', value);
	return (dest);
}
