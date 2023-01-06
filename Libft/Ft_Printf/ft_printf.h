/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:54:50 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/06/23 22:27:12 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h> 
# include <unistd.h>
# include <limits.h>

int				ft_printf(const char *str, ...);
int				ft_format(char c, va_list list);
int				flag_str(char c, va_list list);
int				flag_c(int letter);
int				flag_s(char *str);
int				flag_percentage(void);
int				flag_dec(char c, va_list list);
int				flag_d(int number);
int				flag_i(int number);
int				flag_u(unsigned int number);
int				flag_hex(char c, va_list list);
int				flag_x(unsigned int number, int c);
int				flag_p(unsigned long number);
char			*ft_convert_b10_to_b16(unsigned long n);
int				ft_validate(char *str, int *x, int *y, va_list list);
int				ft_add_char(int arg, int len, char c, char flag);
int				ft_u_add_char(unsigned int arg, int len, char c, char flag);
int				ft_add_str(char *str, int len, char c);
int				ft_size(int n);
int				ft_u_size(unsigned int n);
int				ft_catch_len_value(char *str, int *value);
int				ft_numbers_redirect(unsigned int arg, char *arg_s,
					char *str, char c);
int				ft_auxiliary_dot(char *arg_s, int len);
unsigned int	ft_get_arg(char flag, va_list list);
int				ft_send_arg(char flag, unsigned int arg, char *arg_s);
int				flags_sp(char *str, int *y, va_list list);
int				flag_space(char *str, int *y, va_list list);
int				flag_zero(char *str, int *y, va_list list);
int				flags_justify(char *str, int *y, va_list list);
int				flag_dot(char *str, int *y, va_list list);
int				ft_justify_p(char first, int value, va_list list);
int				ft_size_sixteen(unsigned long n);

#endif