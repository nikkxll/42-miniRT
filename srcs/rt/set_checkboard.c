
#include "../../includes/minirt.h"

t_rgb3	checkboard_fun(t_num x, t_num y, t_rgb3 c1, t_rgb3 c2)
{
	x = x - floor(x);
	y = y - floor(y);
	if ((x <= 0.5 && y <= 0.5) || (x > 0.5 && y > 0.5))
		return (c1);
	return (c2);
}

void	set_chess_plane(t_hit_data *data)
{
	t_plane	*pl;
	t_vec3d	ab[2];
	t_vec3d	m;
	t_num	xy[2];

	pl = (t_plane *)data->obj;
	m = vec_sub(data->v, pl->r);
	if (is_epsilon(pl->n.z))
	{
		ab[0] = cross((t_vec3d){0, 0, 1}, pl->n);
		ab[1] = (t_vec3d){0, 0, 1};
	}
	else
	{
		ab[0] = cross((t_vec3d){1, 0, 0}, pl->n);
		ab[1] = cross((t_vec3d){0, 1, 0}, pl->n);
	}
	xy[0] = dot(ab[0], m) / pl->size_ch;
	xy[1] = dot(ab[1], m) / pl->size_ch;
	data->rgb = checkboard_fun(xy[0], xy[1], data->rgb, pl->rgb_ch);
}

void	set_chess_sphere(t_hit_data *data)
{
	t_sphere	*sp;
	t_vec3d		m;
	t_num		theta;
	t_num		alpha;

	sp = (t_sphere *)data->obj;
	m = vec_unit(vec_sub(data->v, sp->r));
	theta = sp->quan_ch * acos(m.y) / PI;
	alpha = sp->quan_ch * acos(m.x / sqrt(1 - m.y * m.y)) / PI;
	data->rgb = checkboard_fun(alpha, theta, data->rgb, sp->rgb_ch);
}

void	set_chess_cyliner(t_hit_data *data)
{
	t_cylinder	*cy;
	t_vec3d		rr;
	t_num		z;
	t_num		alpha;
	t_vec3d		axis;

	cy = (t_cylinder *)data->obj;
	rr = vec_sub(data->v, cy->r);
	z = cy->quan_ch * (dot(rr, cy->n) + cy->h / 2) / cy->h;
	if (cy->type == CYLINDER)
		rr = data->n;
	else if (cy->type == CONE)
		rr = vec_sub(rr, vec_scale(dot(rr, cy->n), cy->n));
	if (!cy->n.x)
		axis = cross(cy->n, (t_vec3d){1, 0, 0});
	else if (!cy->n.y)
		axis = cross(cy->n, (t_vec3d){0, 1, 0});
	else if (!cy->n.z)
		axis = cross(cy->n, (t_vec3d){0, 0, 1});
	else
		axis = vec_unit(cross(cy->n, (t_vec3d){1, 0, 0}));
	alpha = acos(vec_cos(rr, axis));
	if (dot(cross(rr, axis), cy->n) < 0)
		alpha = 2 * PI - alpha;
	data->rgb = checkboard_fun(cy->quan_ch * alpha / 2 / PI, z, data->rgb, cy->rgb_ch);
}

void	set_checkboard(t_minirt *rt)
{
//	return ;
	int			i;
	t_hit_data	*data;

	i = -1;
	while (++i < rt->vp.size)
	{
		data = &(rt->vp.hit[i]);
		if (data->type == TYPE_OBJ_NONE || data->obj->opt == 0)
			continue ;
		if (data->type == PLANE)
			set_chess_plane(data);
		if (data->type == SPHERE)
			set_chess_sphere(data);
		if (data->type == CYLINDER || data->type == CONE)
			set_chess_cyliner(data);
	}
}
