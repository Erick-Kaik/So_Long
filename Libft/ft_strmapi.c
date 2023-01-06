/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:59:58 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/14 20:19:27 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	size_t	size;
	char	*temp;

	x = 0;
	size = ft_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	temp = malloc((size + 1) * sizeof(char));
	if (temp == NULL)
		return (0);
	while (s[x] != '\0')
	{
		temp[x] = f(x, s[x]);
		x++;
	}
	temp[x] = '\0';
	return (temp);
}
