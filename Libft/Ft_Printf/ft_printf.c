/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:54:34 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/30 18:52:27 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		x;
	int		y;
	va_list	l;

	x = 0;
	y = 0;
	va_start(l, str);
	while (str[x] != '\0')
	{
		if (str[x] == '%' && ft_validate((char *)str + x + 1, &x, &y, l) == 1)
		{
			x++;
			y += ft_format(str[x], l);
			x++;
		}
		if (str[x] == '\0')
			break ;
		else if (str[x] == '%' && ft_strchr("cspdiuxX%# +-0123456789.",
				str[x + 1]))
			continue ;
		y += ft_putchar(str[x]);
		x++;
	}
	va_end(l);
	return (y);
}

int	ft_format(char c, va_list list)
{
	int	value;

	value = 0;
	if (c == 'c' || c == 's' || c == '%')
		value += flag_str(c, list);
	else if (c == 'd' || c == 'i' || c == 'u')
		value += flag_dec(c, list);
	else if (c == 'x' || c == 'X' || c == 'p')
		value += flag_hex(c, list);
	return (value);
}

int	ft_validate(char *str, int *x, int *y, va_list list)
{
	int	value;

	value = 0;
	if (ft_strchr("cspdiuxX%", str[0]))
		value = 1;
	else if (ft_strchr("#+", str[0]))
		*x += flags_sp(str, y, list);
	else if (ft_strchr(" ", str[0]))
		*x += flag_space(str, y, list);
	else if (ft_strchr("0", str[0]))
		*x += flag_zero(str, y, list);
	else if (ft_strchr("-123456789", str[0]))
		*x += flags_justify(str, y, list);
	else if (ft_strchr(".", str[0]))
		*x += flag_dot(str, y, list);
	else
		value = 0;
	return (value);
}
