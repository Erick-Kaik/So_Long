/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:28:46 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/06/23 23:05:28 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;
	size_t	start;
	size_t	end;
	char	*temp;

	x = 0;
	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && ft_check(s1[start], set) == 1)
		start++;
	while (end > start && ft_check(s1[end - 1], set) == 1)
		end--;
	temp = malloc(sizeof(char) * (end - start + 1));
	if (temp == NULL)
		return (NULL);
	while (start < end)
	{
		temp[x] = s1[start];
		x++;
		start++;
	}
	temp[x] = '\0';
	return (temp);
}

static size_t	ft_check(char c, char const *set)
{
	size_t	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}
