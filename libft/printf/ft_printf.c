/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:17 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/03 20:47:53 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats_check(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar_fd_printf(va_arg(args, int), 1));
	else if (*str == 's')
		return (ft_putstr_fd_printf(va_arg(args, char *), 1));
	else if (*str == 'p')
		return (ft_ptr_to_hex(va_arg(args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_itoa_write(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_unsigned_to_str(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_to_hex(va_arg(args, unsigned int), 'x'));
	else if (*str == 'X')
		return (ft_to_hex(va_arg(args, unsigned int), 'X'));
	else if (*str == '%')
		return (ft_putchar_fd_printf('%', 1));
	return (0);
}

static int	string_loop(const char *str, va_list args)
{
	int	length;
	int	temp;

	length = 0;
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(1 + str++)))
		{
			temp = ft_formats_check(str, args);
			if (temp < 0)
				return (-1);
			length += temp;
		}
		else
		{
			if (ft_putchar_fd_printf(*str, 1) < 0)
				return (-1);
			length++;
		}
		str++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, str);
	length = string_loop(str, args);
	va_end(args);
	return (length);
}
