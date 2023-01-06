/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:03:32 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/30 16:23:50 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	else
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

int	ft_u_size(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	else
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

int	ft_catch_len_value(char *str, int *value)
{
	int	len;

	len = 0;
	if (ft_isdigit(str[0]) && str[0] != '0')
		*value = ft_atoi(str);
	else if (ft_isdigit(str[1]))
		*value = ft_atoi(str + 1);
	else if (!ft_isdigit(str[1]))
		*value = 0;
	while (!ft_strchr("cspdiuxX%", str[len]))
		len++;
	return (len);
}

int	ft_auxiliary_dot(char *arg_s, int len)
{
	int	x;

	x = 0;
	while (x < len && arg_s[x] != '\0')
	{
		ft_putchar(arg_s[x]);
		x++;
	}
	return (x);
}

int	ft_justify_p(char first, int value, va_list list)
{
	unsigned int long	arg;
	int					len;
	int					x;

	x = 0;
	arg = va_arg(list, unsigned long);
	len = ft_size_sixteen(arg) + 2;
	if (first == '-')
		x += flag_p(arg);
	while (len < value)
	{
		x += ft_putchar(' ');
		value--;
	}
	if (first != '-')
		x += flag_p(arg);
	return (x);
}
