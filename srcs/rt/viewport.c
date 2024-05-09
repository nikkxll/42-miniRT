#include "../../includes/minirt.h"

t_vec3d	viewport_vec(t_viewport *vp, int i, int j)
{
	t_vec3d	r_vec;
	t_num	v_x;
	t_num	v_y;

	v_x = 2 * TAN(PI * vp->fov / 180 / 2);
	v_y = v_x * vp->n_y / vp->n_x;
	r_vec = vec_add((t_vec3d){0, 0, 1},
			vec_scale((t_num)(2 * i - vp->n_x + 1) / (2 * (vp->n_x - 1)),
				(t_vec3d){v_x, 0, 0}));
	r_vec = vec_add(r_vec,
			vec_scale((t_num)(2 * j - vp->n_y + 1) / (2 * (vp->n_y - 1)),
				(t_vec3d){0, -v_y, 0}));
	r_vec = vec_unit(r_vec);
	return (r_vec);
}

void	hit_scene(t_minirt *rt)
{
	size_t	pixel;

	pixel = 0;
	while (pixel < (size_t)rt->vp.size)
	{
		hit_spheres(rt, pixel);
		hit_planes(rt, pixel);
		hit_cylinder(rt, pixel);
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

void	init_viewport(t_minirt *rt)
{
	int			i;
	int			j;
	int			n;
	t_viewport	*vp;

	vp = &(rt->vp);
	rt->vp = (t_viewport){rt->prs->camera->fov, rt->prs->screen->width, \
		rt->prs->screen->height, \
		rt->prs->screen->width * rt->prs->screen->height, NULL};
	vp->hit = (t_hit_data *)malloc(sizeof(*vp->hit) * vp->size);
	if (!vp->hit)
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	n = 0;
	j = -1;
	while (++j < vp->n_y)
	{
		i = -1;
		while (++i < vp->n_x)
		{
			vp->hit[n].ray = viewport_vec(vp, i, j);
			vp->hit[n].dist = -1;
			vp->hit[n].obst = -1;
			vp->hit[n].rgb = (t_rgb3){0, 0, 0};
			vp->hit[n].color = (t_vec3d){0, 0, 0};
			vp->hit[n].type = TYPE_OBJ_NONE;
			n++;
		}
	}
}
