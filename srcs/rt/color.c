/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:55:15 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/11 18:55:18 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int32_t	rgb_to_int(t_rgb3 rgb)
{
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}

t_vec3d	rgb_to_vec(t_rgb3 rgb)
{
	t_num	r;
	t_num	g;
	t_num	b;
	t_vec3d	vec;

	r = (t_num)rgb.r / 255.0;
	g = (t_num)rgb.g / 255.0;
	b = (t_num)rgb.b / 255.0;
	vec = (t_vec3d){r, g, b};
	return (vec);
}

t_num	ft_min2(t_num x, t_num y)
{
	if (x > y)
		return (y);
	return (x);
}

t_rgb3	vec_to_rgb(t_vec3d c)
{
	int	r;
	int	g;
	int	b;

	r = (int)ft_min2(254, 255.0 * c.x);
	g = (int)ft_min2(254, 255.0 * c.y);
	b = (int)ft_min2(254, 255.0 * c.z);
	return ((t_rgb3){r, g, b});
}
