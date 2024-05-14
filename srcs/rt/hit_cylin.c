/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:06:11 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/14 12:09:52 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
