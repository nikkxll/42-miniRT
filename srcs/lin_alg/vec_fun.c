/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:07:19 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/11 18:07:23 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//vec_fun.c
t_vec3d	vec_def(t_num x, t_num y, t_num z)
{
	t_vec3d	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vec3d	vec_add(t_vec3d a, t_vec3d b)
{
	t_vec3d	p;

	p.x = a.x + b.x;
	p.y = a.y + b.y;
	p.z = a.z + b.z;
	return (p);
}

t_vec3d	vec_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d	p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.z = a.z - b.z;
	return (p);
}

t_vec3d	vec_prod(t_vec3d a, t_vec3d b)
{
	t_vec3d	p;

	p.x = a.x * b.x;
	p.y = a.y * b.y;
	p.z = a.z * b.z;
	return (p);
}

t_vec3d	vec_scale(t_num n, t_vec3d p)
{
	t_vec3d	v;

	v.x = n * p.x;
	v.y = n * p.y;
	v.z = n * p.z;
	return (v);
}
