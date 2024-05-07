#include "../../includes/minirt.h"

void	make_norm_vec_sphere(t_minirt *rt, int pixel)
{
	t_sphere	*s;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	s = (t_sphere *)data->obj;
	data->n = vec_scale(data->dist, data->ray);
	data->n = vec_sub(data->n, s->r);
	data->n = vec_unit(data->n);
	// add n ->  -n  transformation if it observed from inside
}

void	make_norm_vec(t_minirt *rt)
{
	size_t	pixel;
	int		type;

	pixel = 0;
	while (pixel < (size_t)rt->vp.size)
	{
		//printf("test\n");
		type = rt->vp.hit[pixel].type;
		//printf("test\n");
		if (type == SPHERE)
			make_norm_vec_sphere(rt, pixel);
		//else if (rt->vp.hit[pixel].obj->type == PLANE)
		//hit_planes(rt, pixel);
		// hit other objects here
		pixel++;
	}
}

