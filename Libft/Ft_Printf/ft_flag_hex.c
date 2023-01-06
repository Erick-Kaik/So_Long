/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:46:34 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 20:42:55 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_hex(char c, va_list list)
{
	int	value;

	value = 0;
	if (c == 'x' || c == 'X')
		value += flag_x(va_arg(list, unsigned int), c);
	else if (c == 'p')
		value += flag_p(va_arg(list, unsigned long));
	return (value);
}

int	flag_x(unsigned int number, int c)
{
	int		value;
	char	*temp;

	value = 0;
	temp = ft_convert_b10_to_b16(number);
	if (temp != NULL && !(number == 0))
	{
		if (c == 'X')
		{
			while (temp[value] != '\0')
			{
				temp[value] = ft_toupper(temp[value]);
				value++;
			}
		}
		value = ft_putstr(temp);
		free(temp);
	}
	else if (number == 0)
		value = ft_putchar('0');
	return (value);
}

int	flag_p(unsigned long number)
{
	int		value;
	char	*temp;
	char	*aux;

	value = 0;
	aux = ft_convert_b10_to_b16(number);
	if (aux != NULL && !(number == 0))
	{
		temp = ft_strjoin("0x", aux);
		free(aux);
		value = ft_putstr(temp);
		free(temp);
	}
	else if (number == 0)
		value = ft_putstr("(nil)");
	return (value);
}
