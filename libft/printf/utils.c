/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/08 11:09:36 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_printf(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putperc_fd_printf(int fd)
{
	return (write(fd, "%", 1));
}

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		if (ft_putstr_fd_printf("(null)", fd) < 0)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (ft_putchar_fd_printf(*s++, fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}
