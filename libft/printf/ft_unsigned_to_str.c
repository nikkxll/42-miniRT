/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:04:02 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/08 10:28:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uns_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_uns_num_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_uns_str_extractor(char *str, unsigned int nb, int *position)
{
	if (nb < 10)
	{
		ft_uns_char_cpy(str, nb + '0', position);
	}
	else
	{
		ft_uns_str_extractor(str, nb / 10, position);
		ft_uns_char_cpy(str, (nb % 10) + '0', position);
	}
}

int	ft_unsigned_to_str(unsigned int n)
{
	char	*str;
	int		len;
	int		position;

	len = ft_uns_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	position = 0;
	ft_uns_str_extractor(str, n, &position);
	str[position] = '\0';
	if (ft_putstr_fd_printf(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
