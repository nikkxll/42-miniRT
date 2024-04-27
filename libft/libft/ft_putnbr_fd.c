/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:05 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:19:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putnbr_fd(int n, int fd);

// Turn in files: -

// Parameters: n: The integer to output.
// 			   fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the integer ’n’ to the given file
// descriptor.

#include "../libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}
