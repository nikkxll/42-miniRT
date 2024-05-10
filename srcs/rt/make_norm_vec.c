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
		data->n = vec_scale(-1, data->n);
}


void	make_norm_vec_cylin(t_minirt *rt, int pixel)
{
	t_cylinder	*s;
	t_hit_data	*d;

	d = &(rt->vp.hit[pixel]);
	s = (t_cylinder *)d->obj;
	d->v = vec_scale(d->dist, d->ray);
	d->n = vec_sub(d->v, s->r);
	d->n = vec_sub(d->n, \
		vec_scale(d->dist * d->precalc.vn - d->precalc.cn, s->n));
//	d->n = vec_unit(d->n);
	d->n = vec_scale(2 / s->d, d->n);
	if (dot(d->ray, d->n) > 0)
		d->n = vec_scale(-1, d->n);
	if (DEBUG_MOD && dot2(d->n) < 1 - EPSILON)
		printf("n.n != 1 \n");
}

/*
void	make_norm_vec_cone(t_minirt *rt, int pixel)
{
	t_cylinder	*s;
	t_hit_data	*d;
	t_vec3d			vtc;
	t_num				scal_prod;

	d = &(rt->vp.hit[pixel]);
	s = (t_cone *)d->obj;
	d->v = vec_scale(d->dist, d->ray);
	if (vec_norm(vec_sub(d->v, s->r)) < EPSILON)
		d->n = vec_sub(vec_scale(d->precalc.vn, s->n), d->v);
	else
	{
		vtc = vec_sub(d->v, d->precalc.cprime);
		d->n= vec_sub( \
			vec_scale(dot(d->v, vtc), s->r), \
			vec_scale(dot(s->r, vtc), d->v));
	}
	d->n = vec_unit(d->n);
	if (dot(d->ray, d->n) > 0)
		d->n = vec_scale(-1, d->n);
}
*/

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
		else if (type == CYLINDER)
			make_norm_vec_cylin(rt, pixel);
		//else if (rt->vp.hit[pixel].obj->type == PLANE)
		//hit_planes(rt, pixel);
		// hit other objects here
		pixel++;
	}
}

