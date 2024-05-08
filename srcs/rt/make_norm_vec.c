#include "../../includes/minirt.h"

void	make_norm_vec_sphere(t_minirt *rt, int pixel)
{
	t_sphere	*s;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	s = (t_sphere *)data->obj;
	data->v = vec_scale(data->dist, data->ray);
	data->n = vec_sub(data->v, s->r);
	data->n = vec_unit(data->n);
	if (dot(data->ray, data->n) > 0)
	{
	//	printf("norm sign changed\n");
		data->n = vec_scale(-1, data->n);
	}
}

void	make_norm_vec_plane(t_minirt *rt, int pixel)
{
	t_plane		*p;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	p = (t_plane *)data->obj;
	data->v = vec_scale(data->dist, data->ray);
	data->n = p->n;
	if (dot(data->ray, data->n) > 0)
	{
	//	printf("norm sign changed\n");
		data->n = vec_scale(-1, data->n);
	}
}

void	make_norm_vec(t_minirt *rt)
{
	size_t	pixel;
	int		type;

	pixel = 0;
	while (pixel < (size_t)rt->vp.size)
	{
		type = rt->vp.hit[pixel].type;
		if (type == SPHERE)
			make_norm_vec_sphere(rt, pixel);
		else if (type == PLANE)
			make_norm_vec_plane(rt, pixel);
		//else if (rt->vp.hit[pixel].obj->type == PLANE)
		//hit_planes(rt, pixel);
		// hit other objects here
		pixel++;
	}
}

