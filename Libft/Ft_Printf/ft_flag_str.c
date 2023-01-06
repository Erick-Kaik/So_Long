/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:46:39 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/22 00:52:09 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_str(char c, va_list list)
{
	int	value;

	value = 0;
	if (c == 'c')
		value += flag_c(va_arg(list, int));
	else if (c == 's')
		value += flag_s(va_arg(list, char *));
	else if (c == '%')
		value += flag_percentage();
	return (value);
}

int	flag_c(int letter)
{
	int	value;

	value = ft_putchar(letter);
	return (value);
}

int	flag_s(char *str)
{
	int	value;

	if (str == NULL)
		value = ft_putstr("(null)");
	else
		value = ft_putstr(str);
	return (value);
}

int	flag_percentage(void)
{
	int	value;

	value = ft_putchar('%');
	return (value);
}
