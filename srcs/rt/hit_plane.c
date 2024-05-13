#include "../../includes/minirt.h"

static t_num	dist_to_plane(t_plane *pl, t_vec3d v)
{
	t_num	t;
	t_num	div;

	div = dot(v, pl->n);
	if (-EPSILON < div && div < EPSILON)
		return (-1);
	t = dot(pl->r, pl->n) / div;
	if (t > EPSILON)
		return (t);
	return (0);
}

void	hit_planes(t_minirt *rt, size_t pixel)
{
	t_num		t;
	t_plane		*pl;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	pl = rt->prs->plane;
	while (pl)
	{
		t = dist_to_plane(pl, data->ray);
		if (t > 0 && (data->dist == -1 || t < data->dist))
		{
			data->dist = t;
			data->obj = (t_obj *)pl;
			data->type = PLANE;
			data->rgb = pl->rgb;
		}
		pl = pl->next;
	}
}

t_hit_data	touch_planes(t_minirt *rt, t_hit_data *data, t_vec3d l)
{
	t_hit_data	ret;
	t_num		t;
	t_plane		*p;
	t_plane		copy;

	ret.dist = -1;
	p = rt->prs->plane;
	while (p)
	{
		copy = *p;
		copy.r = vec_sub(copy.r, data->v);
		t = dist_to_plane(&copy, l);
		if (t > EPSILON && (data->obst == -1 || t < data->obst))
		{
			ret.dist = t;
			data->obst = t;
			ret.obj = (t_obj *)p;
			ret.type = PLANE;
			ret.rgb = p->rgb;
			if (t < vec_norm(data->ll))
				break ;
		}
		p = p->next;
	}
	return (ret);
}
