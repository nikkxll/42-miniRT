/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:36:45 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:15:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <stdlib.h>
//	void *calloc(size_t count, size_t size);

// DESCRIPTION
//	The calloc() function contiguously allocates enough space for 
//	count objects that are size bytes of memory each and
//	returns a pointer to the allocated memory.  
//	The allocated memory is filled with bytes of value zero.

// RETURN VALUES
//	If successful, calloc(), malloc(), realloc(), reallocf(), and valloc() 
//	functions return a pointer to allocated memory.  
//	If there is an error, they return a NULL pointer and set errno to ENOMEM.

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	num;

	num = (size_t)-1;
	if (count != 0 && (num / count) < size)
		return (NULL);
	num = count * size;
	mem = malloc(num);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, num);
	return (mem);
}
