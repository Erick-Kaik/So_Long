/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transporter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:33:30 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 20:43:51 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_get_arg(char flag, va_list list)
{
	if (ft_strchr("cdi", flag))
		return (va_arg(list, int));
	else if (ft_strchr("uxX", flag))
		return (va_arg(list, unsigned int));
	else if (ft_strchr("p", flag))
		return (va_arg(list, unsigned long));
	return (0);
}

int	ft_send_arg(char flag, unsigned int arg, char *arg_s)
{
	int	x;

	x = 0;
	if (flag == 'c')
		x = flag_c((int)arg);
	else if (flag == 'd')
		x = flag_d((int)arg);
	else if (flag == 'i')
		x = flag_i((int)arg);
	else if (flag == 'p')
		x = flag_p(arg);
	else if (flag == 's')
		x = flag_s(arg_s);
	else if (flag == 'u')
		x = flag_u(arg);
	else if (flag == 'x' || flag == 'X')
		x = flag_x(arg, flag);
	return (x);
}

int	ft_numbers_redirect(unsigned int arg, char *arg_s, char *str, char c)
{
	int	x;
	int	value;

	x = ft_catch_len_value(str, &value);
	if (str[x] == '#')
		value -= 2;
	else if (str[x] == '+' && (int)arg >= 0)
		value -= 1;
	if (ft_strchr("cdi", str[x]))
		x = ft_add_char((int)arg, value, c, str[x]);
	else if (ft_strchr("puxX", str[x]))
		x = ft_u_add_char(arg, value, c, str[x]);
	else if (str[x] == 's')
		x = ft_add_str(arg_s, value, c);
	return (x);
}
