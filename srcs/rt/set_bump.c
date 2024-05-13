/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:28 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/13 22:06:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb3	get_bump_pixel(mlx_texture_t *texture, int i, int j)
{
	int		pos;
	uint8_t	*curr;
	//int k;

	/*k = i;
	i = j;
	j = k;*/
	pos = (j * texture->width / 2 + i) * 4;
	//pos = (j * texture->height / 2 + i) * 4;
	curr = texture->pixels + pos;
	return ((t_rgb3){curr[0], *(curr + 1), *(curr + 2)});
}
