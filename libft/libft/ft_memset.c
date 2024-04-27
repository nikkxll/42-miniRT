/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:09:05 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	void *memset(void *b, int c, size_t len);

// DESCRIPTION
//	The memset() function writes len bytes of value c 
//	(converted to an unsigned char) to the string b.

// RETURN VALUES
//	The memset() function returns its first argument.

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}
