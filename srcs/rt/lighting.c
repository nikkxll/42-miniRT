#include "../../includes/minirt.h"

t_vec3d	rgb_to_vec(t_rgb3 rgb)
{
	t_num	r;
	t_num	g;
	t_num	b;
	t_vec3d	vec;

	r = (t_num)rgb.r / 255.0;
	g = (t_num)rgb.g / 255.0;
	b = (t_num)rgb.b / 255.0;
	vec = (t_vec3d){r, g, b};
	return (vec);
}

t_num	ft_min2(t_num x, t_num y)
{
	if (x > y)
		return (y);
	return (x);
}

t_rgb3	vec_to_rgb(t_vec3d c)
{
	int	r;
	int	g;
	int	b;

	r = (int)ft_min2(255, 255.0 * c.x);
	g = (int)ft_min2(255, 255.0 * c.y);
	b = (int)ft_min2(255, 255.0 * c.z);
	return ((t_rgb3){r, g, b});
}

void lighting(t_minirt *rt, int pixel)
{
	t_hit_data	*data;
	t_light		*l;
	t_am_light	*a;
	t_vec3d		temp;

	data = &(rt->vp.hit[pixel]);
	data->color = vec_scale(COEF_OBJS, rgb_to_vec(data->rgb));
	a = rt->prs->aml;
	data->color = vec_add(data->color, \
		vec_scale(COEF_AMBI * a->ratio, rgb_to_vec(a->rgb)));
	l = rt->prs->light;
	while (l)
	{
		temp = vec_unit(vec_sub(l->r, vec_scale(data->dist, data->ray)));
		temp = vec_scale(COEF_DIFF * l->brt * dot(data->n, temp), \
			rgb_to_vec(l->rgb));
		data->color = vec_add(data->color, temp);
		l = l->next;
	}
}
