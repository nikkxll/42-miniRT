/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:28 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/14 12:02:49 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb3	get_bump_pixel(mlx_texture_t *texture, int i, int j)
{
	int		pos;
	uint8_t	*curr;

	pos = (j * texture->width + i) * 4;
	curr = texture->pixels + pos;
	return ((t_rgb3){curr[0], *(curr + 1), *(curr + 2)});
}
