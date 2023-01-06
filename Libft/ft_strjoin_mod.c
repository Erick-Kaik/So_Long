/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:03:41 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/07 18:58:51 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_mod(char *s1, char *s2)
{
	int		x;
	char	*temp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	x = ft_strlen_mod(s1, '\0') + ft_strlen_mod(s2, '\0') + 1;
	temp = malloc(x);
	if (temp == NULL)
		return (NULL);
	else
	{
		ft_memmove(temp, s1, ft_strlen_mod(s1, '\0'));
		ft_memmove(temp + ft_strlen_mod(s1, '\0'), s2, ft_strlen_mod(s2, '\0'));
		temp[--x] = '\0';
	}
	free(s1);
	return (temp);
}
