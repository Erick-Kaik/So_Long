/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:26:23 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/25 01:27:18 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_size_itoa(size_t *value, size_t *size, unsigned int n);

char	*ft_unsigned_itoa(unsigned int n)
{
	size_t	value;
	size_t	size;
	char	*temp;

	value = 0;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	ft_size_itoa(&value, &size, n);
	temp = (char *)ft_calloc(size + 1, sizeof(char));
	if (temp == NULL)
		return (0);
	size--;
	while (value > 0)
	{
		temp[size--] = value % 10 + '0';
		value /= 10;
	}
	return (temp);
}

static void	ft_size_itoa(size_t *value, size_t *size, unsigned int n)
{
	*value = n;
	while (n != 0)
	{
		n /= 10;
		(*size)++;
	}
}
