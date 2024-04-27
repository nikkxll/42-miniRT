/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:08:15 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/08 10:26:25 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_hex_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	ft_puthex(char *str, unsigned int nb, int *position, char format)
{
	char const	*charset;

	if (format == 'X')
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	if (nb < 16)
	{
		ft_char_cpy(str, charset[nb], position);
	}
	else
	{
		ft_puthex(str, nb / 16, position, format);
		ft_char_cpy(str, charset[nb % 16], position);
	}
}

int	ft_to_hex(unsigned int n, char format)
{
	char	*str;
	int		len;
	int		position;

	position = 0;
	len = ft_hex_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	ft_puthex(str, n, &position, format);
	str[position] = '\0';
	if (ft_putstr_fd_printf(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
