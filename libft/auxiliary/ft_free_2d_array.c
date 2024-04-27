/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:54 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_2d_array(void *ptr)
{
	void	**arr;
	size_t	i;

	arr = (void **)ptr;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
