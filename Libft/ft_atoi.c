/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:54:24 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/11 14:53:35 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		x;
	int		y;
	int		value;
	char	*temp;

	x = 0;
	y = 1;
	value = 0;
	temp = (char *)str;
	if (str == NULL)
		return (0);
	while ((temp[x] >= '\t' && temp[x] <= '\r') || temp[x] == ' ')
		x++;
	if (temp[x] == '-' || temp[x] == '+')
	{
		if (temp[x] == '-')
			y *= -1;
		x++;
	}
	while (temp[x] >= '0' && temp[x] <= '9')
	{
		value = (value * 10) + temp[x] - '0';
		x++;
	}
	return (value * y);
}
