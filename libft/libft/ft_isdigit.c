/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:52 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:15:54 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isdigit(int c);

// DESCRIPTION
//	The isdigit() function tests for a decimal digit character.
//	Regardless of locale, this includes the following char-
//	acters only:

//      ``0''         ``1''         ``2''         ``3''         ``4''
//      ``5''         ``6''         ``7''         ``8''         ``9''

// RETURN VALUES
//	The isdigit() and isnumber() functions return zero if 
//	the character tests false and return non-zero if the character
//	tests true.

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
