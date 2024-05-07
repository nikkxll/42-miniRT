#include "../../includes/minirt.h"

static t_num	dist_to_sphere(t_sphere *sp, t_vec3d v)
{
	t_num	denom;
	t_num	prod;
	t_num	t[2];

	prod = dot(v, sp->r);
	denom = prod * prod - dot2(sp->r) + POW(sp->d, 2) / 4;
	if (denom < EPSILON)
		return (-1);
	t[0] = SQRT(denom);
	t[1] = (-1) * t[0];
	t[0] += prod;
	t[1] += prod;
	if (t[1] > EPSILON)
		return (t[1]);
	if (t[0] > EPSILON)
		return (t[0]);
	return (0);
}

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
