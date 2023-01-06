/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:28:16 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/04/29 21:56:01 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_size_negative(size_t *value, size_t *neg, size_t *size, int n);

char	*ft_itoa(int n)
{
	size_t	value;
	size_t	size;
	size_t	neg;
	char	*temp;

	value = 0;
	neg = 0;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_size_negative(&value, &neg, &size, n);
	temp = (char *)ft_calloc(size + 1, sizeof(char));
	if (temp == NULL)
		return (0);
	size--;
	while (value > 0)
	{
		temp[size--] = value % 10 + '0';
		value /= 10;
	}
	if (neg == 1)
		temp[size] = '-';
	return (temp);
}

static void	ft_size_negative(size_t *value, size_t *negative,
size_t *size, int n)
{
	if (n < 0)
	{
		*negative = 1;
		*value = n * -1;
		(*size)++;
	}
	else
		*value = n;
	while (n != 0)
	{
		n /= 10;
		(*size)++;
	}
}
