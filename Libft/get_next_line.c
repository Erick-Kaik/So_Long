/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:29:50 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/06/23 23:08:12 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_get_line(int fd, char *str, int *value);
void	*ft_line(char *str, size_t len, int value);
void	*ft_next_line(char *str, size_t len, int value);

char	*get_next_line(int fd)
{
	size_t			len;
	int				value;
	char			*line;
	static char		*str[257];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_get_line(fd, str[fd], &value);
	if (str[fd] == NULL)
		return (NULL);
	if (value != 0)
		len = ft_strlen_mod(str[fd], '\n');
	else
		len = ft_strlen_mod(str[fd], '\0');
	line = ft_line(str[fd], len, value);
	str[fd] = ft_next_line(str[fd], len, value);
	return (line);
}

void	*ft_get_line(int fd, char *str, int *value)
{
	char	*temp;

	*value = 1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (*value != 0 && !ft_strchr(str, '\n'))
	{
		*value = read(fd, temp, BUFFER_SIZE);
		if (*value == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[*value] = '\0';
		str = ft_strjoin_mod(str, temp);
	}
	free(temp);
	return (str);
}

void	*ft_line(char *str, size_t len, int value)
{
	size_t	x;
	char	*line;

	x = 0;
	if (str[x] == '\0')
		return (NULL);
	if (value != 0)
		line = malloc((len + 2) * sizeof(char));
	else
		line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (str[x] != '\n' && str[x] != '\0')
	{
		line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

void	*ft_next_line(char *str, size_t len, int value)
{
	size_t	x;
	char	*temp;

	x = ft_strlen_mod(str, '\0');
	if (str[x] == '\0' && value == 0)
	{
		free(str);
		return (NULL);
	}
	temp = malloc((x - len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	x = 0;
	len++;
	while (str[len] != '\0')
	{
		temp[x] = str[len];
		x++;
		len++;
	}
	temp[x] = '\0';
	free(str);
	return (temp);
}
