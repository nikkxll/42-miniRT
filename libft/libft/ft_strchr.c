/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:21:41 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:19:08 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	char *strchr(const char *s, int c);

// DESCRIPTION
//	The strchr() function locates the first occurrence of c (converted to 
//	a char) in the string pointed to by s.  The terminating null character 
//	is considered to be part of the string; therefore if c is `\0', the 
//	functions locate the terminating `\0'.

// RETURN VALUES
//	The functions strchr() and strrchr() return a pointer to the 
//	located character, or NULL if the character does not
//	appear in the string.

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
