/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:27:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 13:34:48 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: void ft_putstr_fd(char *s, int fd);

// Turn in files: -

// Parameters s: The string to output.
// 			  fd: The file descriptor on which to write.

// Return value: None

// External functs.: write

// Description: Outputs the string ’s’ to the given file
// descriptor.

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	write(fd, s, ft_strlen(s));
}
