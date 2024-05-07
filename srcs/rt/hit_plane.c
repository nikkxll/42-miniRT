#include "../../includes/minirt.h"

static t_num	dist_to_plane(t_plane *pl, t_vec3d v)
{
	t_num	t;
	t_num	div;

	div = dot(v, pl->n);
	if (-EPSILON <div && div < EPSILON)
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
			data->type = PLANE; // this is for convinience . type also is inside the obj
			data->rgb = pl->rgb; // this probably temporal 
		}
		pl = pl->next;
	}
}
