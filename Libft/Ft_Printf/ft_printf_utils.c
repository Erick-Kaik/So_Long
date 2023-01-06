/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:00:05 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/05/28 01:28:14 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_b10_to_b16(unsigned long n)
{
	int		len;
	char	*temp;
	char	*base16;

	if (n != 0)
		len = ft_size_sixteen(n);
	else
		return (NULL);
	base16 = "0123456789abcdef";
	temp = malloc(len + 1 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[len--] = '\0';
	while (n >= 16)
	{
		temp[len--] = base16[n % 16];
		n /= 16;
	}
	if (n < 16)
		temp[len] = base16[n];
	return (temp);
}

int	ft_size_sixteen(unsigned long n)
{
	int	len;

	len = 0;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	if (n < 16)
		len++;
	return (len);
}

int	ft_add_char(int arg, int len, char c, char flag)
{
	int	x;

	x = 0;
	if (flag == 'c')
	{
		if (arg < 0 || arg > 255 || !ft_isdigit(arg))
			arg = 0;
		else if (ft_isdigit(arg))
			arg -= '0';
	}
	if (arg < 0)
	{
		arg *= -1;
		len--;
	}
	while (ft_size(arg) < len)
	{
		x += ft_putchar(c);
		len--;
	}
	return (x);
}

int	ft_u_add_char(unsigned int arg, int len, char c, char flag)
{
	int	x;

	x = 0;
	if (flag == 'p' || flag == 'x' || flag == 'X')
	{
		arg = ft_size_sixteen((unsigned long)arg);
		if (flag == 'p')
			arg += 2;
		while ((int)arg < len)
		{
			x += ft_putchar(c);
			len--;
		}
	}
	else
	{
		while (ft_u_size(arg) < len)
		{
			x += ft_putchar(c);
			len--;
		}
	}
	return (x);
}

int	ft_add_str(char *str, int len, char c)
{
	int	x;
	int	aux;

	x = 0;
	aux = ft_strlen(str);
	while (aux < len)
	{
		x += ft_putchar(c);
		len--;
	}
	return (x);
}
