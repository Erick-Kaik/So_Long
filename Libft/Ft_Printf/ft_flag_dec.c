/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:46:37 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 20:41:15 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_dec(char c, va_list list)
{
	int	value;

	value = 0;
	if (c == 'd')
		value += flag_d(va_arg(list, int));
	else if (c == 'i')
		value += flag_i(va_arg(list, int));
	else if (c == 'u')
		value += flag_u(va_arg(list, unsigned int));
	return (value);
}

int	flag_d(int number)
{
	int		value;
	char	*temp;

	value = 0;
	temp = ft_itoa(number);
	if (temp != NULL)
	{
		value = ft_putstr(temp);
		free(temp);
	}
	return (value);
}

int	flag_i(int number)
{
	int		value;
	char	*temp;

	value = 0;
	temp = ft_itoa(number);
	if (temp != NULL)
	{
		value = ft_putstr(temp);
		free(temp);
	}
	return (value);
}

int	flag_u(unsigned int number)
{
	int		value;
	char	*temp;

	value = 0;
	temp = ft_unsigned_itoa(number);
	if (temp != NULL)
	{
		value = ft_putstr(temp);
		free(temp);
	}
	return (value);
}
