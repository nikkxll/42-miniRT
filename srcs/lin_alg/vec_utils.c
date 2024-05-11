/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:07:33 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/11 18:07:35 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_num	vec_norm(t_vec3d v)
{
	return ((t_num)sqrt(dot(v, v)));
}

t_vec3d	vec_unit(t_vec3d p)
{
	t_vec3d	nv;
	t_num	norm;

	norm = vec_norm(p);
	nv.x = p.x / norm;
	nv.y = p.y / norm;
	nv.z = p.z / norm;
	return (nv);
}

t_num	vec_sin(t_vec3d a, t_vec3d b)
{
	return (sqrt(1 - pow(vec_cos(a, b), 2)));
}

t_num	vec_cos(t_vec3d a, t_vec3d b)
{
	return (dot(a, b) / (vec_norm(a) * vec_norm(b)));
}

void	vec_print(char *str, t_vec3d vec)
{
	printf("%s = (%.2f, %.2f, %.2f)\n", \
		str, \
		(float)vec.x, (float)vec.y, (float)vec.z);
}
