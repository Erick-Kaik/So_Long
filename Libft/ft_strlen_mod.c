/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:02:27 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/07 18:58:57 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_mod(const char *str, char c)
{
	size_t	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x] != c)
		x++;
	return (x);
}
