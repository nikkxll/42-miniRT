/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:14:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:15:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isprint(int c);

// DESCRIPTION
//	The isprint() function tests for any printing character, 
//	including space (` '). The value of the argument must be
//	representable as an unsigned char or the value of EOF.

// RETURN VALUES
//	The isprint() function returns zero if the character tests false 
//	and returns non-zero if the character tests true.

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
