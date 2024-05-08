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

	r = (int)ft_min2(254, 255.0 * c.x);
	g = (int)ft_min2(254, 255.0 * c.y);
	b = (int)ft_min2(254, 255.0 * c.z);
	return ((t_rgb3){r, g, b});
}

void add_light_ambient(t_minirt *rt, t_hit_data *data)
{
	t_am_light	*a;

	a = rt->prs->aml;
	data->color = vec_add(data->color, \
		vec_scale(COEF_AMBI * a->ratio, rgb_to_vec(a->rgb)));
}

/*
int	is_light_sphere(t_minirt *rt, t_hit_data *data)
{
	t_sphere	s;
	t_num 		t;

	s = *((t_sphere *)data->obj);
	s.r = vec_sub(s.r, data->v);
	t = dist_to_sphere(&s, data->l);
	return (1);
}
*/

int	is_light_visible(t_minirt *rt, t_hit_data *data)
{
	t_num t;

	t = touch_spheres(rt, data, data->l).dist; 
	if (t >= 0)
		return (0);
	return (1);
}


void lighting(t_minirt *rt, int pixel)
{
	t_hit_data	*data;
	t_light		*light;
//	t_vec3d		l;
	t_num		prod;
//	t_num		prod_nv;

	data = &(rt->vp.hit[pixel]);

	data->color = vec_scale(COEF_OBJS, rgb_to_vec(data->rgb));
	if (data->dist < 0)
		return ;
	add_light_ambient(rt, data);
	light = rt->prs->light;
	while (light)
	{
		data->l = vec_unit(vec_sub(light->r, data->v));
		prod = dot(data->n, data->l);
		//prod_nv = dot(data->n, data->v);
		if (prod > 0 && is_light_visible(rt, data))
		{
			//printf("i = %d, here is light\n", pixel);
			data->temp = vec_scale(COEF_DIFF * light->brt * prod, \
				rgb_to_vec(light->rgb));
			data->color = vec_add(data->color, data->temp);
			data->temp = vec_sub(vec_scale(2 * prod, data->n), data->l);
			//prod = dot(data->temp, vec_unit(vec_scale(data->dist, data->ray)));
			prod = -1 * dot(data->temp, data->ray);
			if (prod > 0)
			{
				prod = COEF_SPEC * light->brt * POW(prod, COEF_ALPHA);
				data->temp = vec_scale(prod, rgb_to_vec(light->rgb));
				data->color =vec_add(data->color, data->temp);
			}
		}
		light = light->next;
	}
}
