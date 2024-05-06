#include "../../includes/minirt.h"

t_vec3d	viewport_vec(t_viewport *vp, int i, int j)
{
	t_vec3d	r_vec;
	t_num	v_x;
	t_num	v_y;

	v_x = 2 * TAN(PI * vp->foc / 180 / 2);
	v_y = v_x * IMAGE_HIGHT / IMAGE_WIDTH;
	r_vec = vec_add((t_vec3d){0, 0, 1},
			vec_scale((t_num)(2 * i - vp->n_x + 1) / (2 * (vp->n_x - 1)),
				(t_vec3d){v_x, 0, 0}));
	r_vec = vec_add(r_vec,
			vec_scale((t_num)(2 * j - vp->n_y + 1) / (2 * (vp->n_y - 1)),
				(t_vec3d){0, -v_y, 0}));
	r_vec = vec_unit(r_vec);
	return (r_vec);
}

t_num	dist_to_sphere(t_sphere *sp, t_vec3d v)
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
	t_num t;
	t_sphere *s;
	t_hit_data *data;

	data = &(rt->vp.hit[pixel]);
	s = rt->prs->sphere;
	while (s)
	{
		t = dist_to_sphere(s,data->ray);
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

void	hit_scene(t_minirt *rt)
{
	size_t	pixel;

	pixel = 0;
	while (pixel < (size_t)rt->vp.size)
	{
		hit_spheres(rt, pixel);
		//hit_planes(rt, pixel);
		// hit other objects here
		pixel++;
	}
}

/*
void set_colors(t_minirt *rt)
{
	size_t	pixel;
	t_hit_data	*data;

	pixel = 0;
	while (pixel < rt->vp.size)
	{
		data = &(rt->vp.hit[pixel]);
		data->rgb = color
		//hit_planes(rt, pixel);
		// hit other objects here
		pixel++;
	}
}
*/

void	init_viewport(t_viewport *vp)
{
	int	i;
	int	j;
	int	n;

	vp->size = vp->n_x * vp->n_y;
	vp->hit = NULL;
	vp->hit = (t_hit_data *)malloc(sizeof(*vp->hit) * vp->size);
	// protect malloc
	n = 0;
	j = -1;
	while (++j < vp->n_y)
	{
		i = -1;
		while (++i < vp->n_x)
		{
			vp->hit[n].ray = viewport_vec(vp, i, j);
			vp->hit[n].dist = -1;
			vp->hit[n].rgb = (t_rgb3){0,0,0};
			n++;
		}
	}
}
