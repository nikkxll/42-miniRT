/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:20:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/14 18:22:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1_end;
	const unsigned char	*str2_end;

	str1_end = (const unsigned char *)s1;
	str2_end = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1_end != '\0' && *(str1_end + 1) != '\0')
		str1_end++;
	while (*str2_end != '\0' && *(str2_end + 1) != '\0')
		str2_end++;
	while (n-- > 0)
	{
		if (str1_end < (const unsigned char *)s1
			|| str2_end < (const unsigned char *)s2)
			return (0);
		if (*str1_end != *str2_end)
			return (*str1_end - *str2_end);
		str1_end--;
		str2_end--;
	}
	return (0);
}
