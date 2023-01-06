/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:19:31 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/19 20:32:03 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	char	*temp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2) + 1;
	temp = malloc(x);
	if (temp == NULL)
		return (NULL);
	else
	{
		ft_memmove(temp, s1, ft_strlen(s1));
		ft_memmove(temp + ft_strlen(s1), s2, ft_strlen(s2));
		temp[--x] = '\0';
	}
	return (temp);
}
