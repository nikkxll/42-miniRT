#include "../../includes/minirt.h"

t_num	dist_to_sphere_from(t_sphere *sp, t_vec3d v0, t_vec3d v)
{
	t_vec3d r;
	t_num	denom;
	t_num	prod;
	t_num	t[2];

	r = vec_sub(sp->r, v0); 
	prod = dot(v, r);
	denom = prod * prod - dot2(r) + POW(sp->d, 2) / 4;
	if (denom < 0) // EPSILON)
		return (-1);
	t[0] = SQRT(denom);
	t[1] = prod + (-1) * t[0];
	t[0] += prod;
	if (t[1] > 0) //EPSILON)
		return (t[1]);
	if (t[0] > 0) //EPSILON)
		return (t[0]);
	return (0);
}

t_num	dist_to_sphere(t_sphere *sp, t_vec3d v)
{
	t_vec3d v0;
	t_num		t;

	v0 = (t_vec3d){0,0,0};
	t = dist_to_sphere_from(sp, v0, v);
	return (t);
}

/*
t_num	dist_to_sphere(t_sphere *sp, t_vec3d v)
{
	t_num	denom;
	t_num	prod;
	t_num	t[2];

	prod = dot(v, sp->r);
	denom = prod * prod - dot2(sp->r) + POW(sp->d, 2) / 4;
	if (denom < 0) // EPSILON)
		return (-1);
	t[0] = SQRT(denom);
	t[1] = (-1) * t[0];
	t[0] += prod;
	t[1] += prod;
	if (t[1] > 0) //EPSILON)
		return (t[1]);
	if (t[0] > 0) //EPSILON)
		return (t[0]);
	return (0);
}
*/

void	hit_spheres(t_minirt *rt, size_t pixel)
{
	t_num		t;
	t_sphere	*s;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	s = rt->prs->sphere;
	while (s)
	{
		t = dist_to_sphere(s, data->ray);
		if (t > 0 && (data->dist == -1 || t < data->dist))
		{
			data->dist = t;
			data->obj = (t_obj *)s;
			data->type = SPHERE; // this is for convinience . type also is inside the obj
			data->rgb = s->rgb; // this probably temporal 
		}
		s = s->next;
	}
}

t_hit_data touch_spheres(t_minirt *rt, t_hit_data *data, t_vec3d l)
{
	t_hit_data	ret;
	t_num				t;
	t_sphere		*s;
	t_sphere		copy;

	ret.dist = -1;
	s = rt->prs->sphere;
	while (s)
	{
		copy = *s;
		copy.r = vec_sub(copy.r, data->v);
//		t = dist_to_sphere(&copy, l);
		if (s != (t_sphere *)data->obj)
			t = dist_to_sphere(&copy, l);
		else
			t = -1;
		if (t > 0 && (ret.dist == -1 || t < ret.dist))
		{
			ret.dist = t;
			ret.obj = (t_obj *)s;
			ret.type = SPHERE;
			ret.rgb = s->rgb; 
		}
		s = s->next;
	}
	return (ret);
}
