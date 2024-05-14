/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:06:11 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/14 06:06:17 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	is_epsilon(t_num	a)
{
	if (-EPSILON < a && a < EPSILON)
		return (1);
	return (0);
}

// x = num of solutions, y = first solution, z = second
t_vec3d	solve_equation(t_num a, t_num b, t_num c)
{
	t_num	d;

	if (is_epsilon(a))
	{
		if (is_epsilon(b))
			return ((t_vec3d){(t_num)is_epsilon(c), 0, 0});
		return ((t_vec3d){1, -c / b, 0});
	}
	d = b * b - 4 * a * c;
	if (d < 0)
		return ((t_vec3d){0, 0, 0});
	d = sqrt(d);
	if (a > 0)
		return ((t_vec3d){2, (-b - d) / a / 2, (-b + d) / a / 2});
	return ((t_vec3d){2, (-b + d) / a / 2, (-b - d) / a / 2});
}

void	init_dist_cylin(t_dist_cc *var, t_vec3d v0, t_vec3d v, t_cylinder *obj)
{
	var->k1 = 1;
	var->k2 = 0;
	if (obj->type == CYLINDER)
		var->k2 = obj->d * obj->d / 4;
	else if (obj->type == CONE)
		var->k1 = 1 + obj->d * obj->d / obj->h / obj->h;
	var->cprime = vec_sub(obj->r, v0);
	var->vn = dot(v, obj->n);
	var->cn = dot(var->cprime, obj->n);
	var->cv = dot(var->cprime, v);
	var->c2 = dot2(var->cprime);
}

int	is_cylin_h(t_dist_cc *v, t_num t, t_num h)
{
	t_num	hight2;

	hight2 = t * t * v->vn * v->vn - 2 * v->vn * v->cn * t + v->cn * v->cn;
	return (hight2 + EPSILON < h * h / 4);
}

// this function is also to be used for cone
t_num	dist_to_cylin(t_vec3d v0, t_vec3d v1, t_cylinder *obj, t_dist_cc *v)
{
	t_vec3d		t;

	init_dist_cylin(v, v0, v1, obj);
	t = solve_equation(1 - v->k1 * v->vn * v->vn, \
		-2 * (v->cv - v->k1 * v->vn * v->cn), \
		v->c2 - v->k1 * v->cn * v->cn - v->k2);
	if ((t.x == 1 || t.x == 2) && t.y >= EPSILON && is_cylin_h(v, t.y, obj->h))
		return (t.y);
	if (t.x == 2 && t.z >= EPSILON && is_cylin_h(v, t.z, obj->h))
		return (t.z);
	return (-1);
}

void	hit_cylinder_cone(t_minirt *rt, size_t pixel)
{
	t_num		t;
	t_cylinder	*s;
	t_hit_data	*data;
	t_dist_cc	precalc;

	data = &(rt->vp.hit[pixel]);
	s = rt->prs->cylinder;
	if (!s)
		s = (t_cylinder *)rt->prs->cone;
	while (s)
	{
		t = dist_to_cylin((t_vec3d){0, 0, 0}, data->ray, s, &precalc);
		if (t > 0 && (data->dist == -1 || t < data->dist))
		{
			data->dist = t;
			data->obj = (t_obj *)s;
			data->type = s->type;
			data->rgb = s->rgb;
			data->precalc = precalc;
		}
		if (!s->next && s->type == CYLINDER)
			s = (t_cylinder *)rt->prs->cone;
		else
			s = (t_cylinder *)s->next;
	}
}

void	set_dat_cy_co(t_hit_data *ret, t_cylinder *s, t_num t, t_dist_cc *p)
{
	ret->dist = t;
	ret->obj = (t_obj *)s;
	ret->type = s->type;
	ret->rgb = s->rgb;
	ret->precalc = *p;
}

t_hit_data	touch_cylinder_cone(t_minirt *rt, t_hit_data *data, t_vec3d l)
{
	t_hit_data	ret;
	t_num		t;
	t_cylinder	*s;
	t_cylinder	copy;
	t_dist_cc	precalc;

	ret.dist = -1;
	s = rt->prs->cylinder;
	if (!s)
		s = (t_cylinder *)rt->prs->cone;
	while (s)
	{
		copy = *s;
		t = dist_to_cylin(data->v, l, &copy, &precalc);
		if (t > EPSILON && (data->obst == -1 || t < data->obst))
			set_dat_cy_co(&ret, s, t, &precalc);
		if (!s->next && s->type == CYLINDER)
			s = (t_cylinder *)rt->prs->cone;
		else
			s = (t_cylinder *)s->next;
	}
	return (ret);
}
