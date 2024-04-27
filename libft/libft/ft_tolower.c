/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:20:24 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:19:46 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int tolower(int c);

// DESCRIPTION
//	The tolower() function converts an upper-case letter to the 
//	corresponding lower-case letter.  The argument must be
//	representable as an unsigned char or the value of EOF.

//	Although the tolower() function uses the current locale, 
//	the tolower_l() function may be passed a locale directly.
//	See xlocale(3) for more information.

// RETURN VALUES
//	If the argument is an upper-case letter, the tolower() function returns 
//	the corresponding lower-case letter if there
//	is one; otherwise, the argument is returned unchanged.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
