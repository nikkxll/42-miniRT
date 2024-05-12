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
	// handle the case of (r x n) = 0
	t_plane	*pl;
	t_vec3d ab[2];
	t_vec3d	m;
	t_num		xy[2];

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
	xy[0] = dot(ab[0], m);
	xy[1] = dot(ab[1], m);
	data->rgb = checkboard_fun(xy[0], xy[1], data->rgb, (t_rgb3){0,0,0});
}

void	set_checkboard(t_minirt *rt)
{
//	return ;
	int	i;
	t_hit_data *data;

	i = -1;
	while (++i < rt->vp.size)
	{
		data = &(rt->vp.hit[i]);
		if (data->type == TYPE_OBJ_NONE)
			continue;
		if (data->type == PLANE)
			set_chess_plane(data);
	}
}
