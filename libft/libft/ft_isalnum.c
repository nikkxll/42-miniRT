/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:31:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:15:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isalnum(int c);

// DESCRIPTION
//	The isalnum() function tests for any character for which isalpha(3) 
//	or isdigit(3) is true.  The value of the argument
//	must be representable as an unsigned char or the value of EOF.

// RETURN VALUES
//	The isalnum() function returns zero if the character tests 
//	false and returns non-zero if the character tests true.

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57))
		|| ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
