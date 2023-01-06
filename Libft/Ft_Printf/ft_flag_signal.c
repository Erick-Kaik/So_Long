/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:47:20 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/30 17:29:33 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_sp(char *str, int *y, va_list list)
{
	unsigned int	arg;
	int				value;
	int				len;

	len = ft_catch_len_value(str, &value);
	arg = ft_get_arg(str[len], list);
	*y += ft_numbers_redirect(arg, "", str, ' ');
	if (ft_strchr("+", str[0]) && (int)arg >= 0)
		*y += ft_putchar(str[0]);
	else if (ft_strchr("#", str[0]) && arg != 0)
	{
		if (str[len] == 'x')
			*y += ft_putstr("0x");
		else if (str[len] == 'X')
			*y += ft_putstr("0X");
	}
	*y += ft_send_arg(str[len], arg, "");
	return (len + 2);
}

int	flag_zero(char *str, int *y, va_list list)
{
	unsigned int	arg;
	int				value;
	int				len;
	char			*arg_s;

	arg = 0;
	arg_s = "";
	len = ft_catch_len_value(str, &value);
	if (str[len] == 's')
		arg_s = va_arg(list, char *);
	else
		arg = ft_get_arg(str[len], list);
	if (ft_strchr("cdi", str[len]) && value > 0 && (int)arg < 0
		&& (int)arg != -2147483648)
	{
		*y += ft_putchar('-');
		*y += ft_numbers_redirect(arg, arg_s, str, '0');
		arg *= -1;
	}
	else if (value > 0)
		*y += ft_numbers_redirect(arg, arg_s, str, '0');
	*y += ft_send_arg(str[len], arg, arg_s);
	return (len + 2);
}

int	flags_justify(char *str, int *y, va_list list)
{
	unsigned int	arg;
	int				value;
	int				len;
	char			*arg_s;

	arg = 0;
	arg_s = "";
	len = ft_catch_len_value(str, &value);
	if (str[len] == 's')
		arg_s = va_arg(list, char *);
	else if (str[len] == 'p')
	{
		*y += ft_justify_p(str[0], value, list);
		return (len + 2);
	}
	else
		arg = ft_get_arg(str[len], list);
	if (str[0] == '-')
		*y += ft_send_arg(str[len], arg, arg_s);
	if (value > 0)
		*y += ft_numbers_redirect(arg, arg_s, str, ' ');
	if (str[0] != '-')
		*y += ft_send_arg(str[len], arg, arg_s);
	return (len + 2);
}

int	flag_dot(char *str, int *y, va_list list)
{
	unsigned int	arg;
	int				value;
	int				len;
	char			*arg_s;

	arg = 0;
	arg_s = "";
	len = ft_catch_len_value(str, &value);
	if (str[len] == 's')
		arg_s = va_arg(list, char *);
	else
		arg = ft_get_arg(str[len], list);
	if (str[len] == 's')
		*y += ft_auxiliary_dot(arg_s, value);
	else if (ft_strchr("cdi", str[len]) && (int)arg < 0 && (int)arg != INT_MIN)
	{
		*y += ft_putchar('-');
		*y += ft_numbers_redirect((arg * -1), arg_s, str, '0');
		arg *= -1;
	}
	else if (value > 0)
		*y += ft_numbers_redirect(arg, arg_s, str, '0');
	if (str[len] != 's')
		*y += ft_send_arg(str[len], arg, arg_s);
	return (len + 2);
}

int	flag_space(char *str, int *y, va_list list)
{
	unsigned int	arg;
	int				value;
	int				len;
	char			*arg_s;

	arg = 0;
	arg_s = "";
	len = ft_catch_len_value(str, &value);
	if (str[len] == 's')
		arg_s = va_arg(list, char *);
	else
		arg = ft_get_arg(str[len], list);
	if (value > 0)
		*y += ft_numbers_redirect(arg, arg_s, str, ' ');
	if (ft_strchr(" ", str[0]) && (int)arg >= 0 && str[len] != 's')
		*y += ft_putchar(str[0]);
	*y += ft_send_arg(str[len], arg, arg_s);
	return (len + 2);
}
