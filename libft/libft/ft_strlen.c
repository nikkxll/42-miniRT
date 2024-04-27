/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:50:07 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:19:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	size_t strlen(const char *s);

// DESCRIPTION
//	The strlen() function computes the length of the string s.  
//	The strnlen() function attempts to compute the length of
//	s, but never scans beyond the first maxlen bytes of s.

// RETURN VALUES
//	The strlen() function returns the number of characters that precede the 
//	terminating NUL character.  The strnlen() function returns either the 
//	same result as strlen() or maxlen, whichever is smaller.

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
