/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:28 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/08 10:26:20 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_num_len(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_str_extractor(char *str, int nb, int *position)
{
	if (nb < 0)
	{
		ft_char_cpy(str, '-', position);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_char_cpy(str, nb + '0', position);
	}
	else
	{
		ft_str_extractor(str, nb / 10, position);
		ft_char_cpy(str, (nb % 10) + '0', position);
	}
}

int	ft_itoa_write(int n)
{
	char	*str;
	int		len;
	int		position;

	if (n == -2147483648)
	{
		if (ft_putstr_fd_printf("-2147483648", 1) < 0)
			return (-1);
		return (11);
	}
	len = ft_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	position = 0;
	ft_str_extractor(str, n, &position);
	str[position] = '\0';
	if (ft_putstr_fd_printf(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
