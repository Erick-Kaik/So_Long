/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:00:04 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 16:41:20 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *str, char c);
static char		**ft_split_words(char const *str, char c, char **temp,
					size_t count);
static char		*ft_fill(char *temp, char const *s, size_t x, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	temp = (char **)malloc(sizeof(char *) * (count + 1));
	if (temp == NULL)
		return (NULL);
	ft_split_words(s, c, temp, count);
	return (temp);
}

static size_t	ft_count(char const *str, char c)
{
	size_t	x;
	size_t	count;

	x = 0;
	count = 0;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			x++;
		else
		{
			count++;
			while (str[x] != c && str[x] != '\0')
				x++;
		}
	}
	return (count);
}

static char	**ft_split_words(char const *str, char c, char **temp, size_t count)
{
	size_t	x;
	size_t	word;
	size_t	len;

	x = 0;
	word = 0;
	len = 0;
	while (word < count)
	{
		while (str[x] != '\0' && str[x] == c)
			x++;
		while (str[x] != '\0' && str[x] != c)
		{
			x++;
			len++;
		}
		temp[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (temp[word] == NULL)
			return (NULL);
		ft_fill(temp[word], str, x, len);
		len = 0;
		word++;
	}
	temp[word] = NULL;
	return (temp);
}

static char	*ft_fill(char *temp, char const *s, size_t x, size_t len)
{
	size_t	y;

	y = 0;
	while (len > 0)
	{
		temp[y] = s[x - len];
		y++;
		len--;
	}
	temp[y] = '\0';
	return (temp);
}
