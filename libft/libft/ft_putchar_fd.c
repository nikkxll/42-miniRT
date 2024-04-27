/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:25:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:57 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putchar_fd(char c, int fd);

// Turn in files: -

// Parameters: c: The character to output.
//			   fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the character ’c’ to the given file
// descriptor.

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
