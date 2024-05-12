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
	t_vec3d	xy;
	t_plane	*pl;
	t_vec3d	m;
	t_vec3d y_unit;
//	t_num		norm;

	pl = (t_plane *)data->obj;
//	norm = vec_norm(vec_sub(data->v, pl->r));
	m = vec_sub(data->v, pl->r);
	// handle the case of (r x n) = 0 
	y_unit = vec_unit(cross(pl->r, pl->n));
	if (is_epsilon(pl->n.y) && is_epsilon(pl->n.x))
		xy = m;
	else
	{
		xy.x = dot(y_unit, m);
		xy.y = dot(\
			vec_unit(vec_sub(vec_scale(dot(pl->r, pl->n), pl->n), pl->r)), \
			m);
	}
	data->rgb = checkboard_fun(xy.x, xy.y, data->rgb, (t_rgb3){0,0,0});
}

void	set_checkboard(t_minirt *rt)
{
//return ;
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
