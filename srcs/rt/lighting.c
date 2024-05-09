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


void add_light_reflected_obj(t_minirt *rt, t_hit_data *data)
{
	t_vec3d	c;

	c = touch_spheres(rt, data, data->r).color;
	c = vec_scale(COEF_REFLECT * 10000, c);
	data->color = vec_add(data->color, c);
}

int	is_light_visible(t_minirt *rt, t_hit_data *data)
{
	//t_num	t_min;
	data->obst = -1;
	touch_spheres(rt, data, data->l);
	touch_planes(rt, data, data->l);
	if (data->obst > EPSILON && data->obst + EPSILON < vec_norm(data->ll))
	{
	//	printf("is_light_visible: t=%lf, light distance =%lf\n", t_min, vec_norm(data->ll));
		return (0);
	}
	return (1);
}




void lighting(t_minirt *rt, int pixel)
{
	t_hit_data	*data;
	t_light		*light;
	t_num		prod;

	data = &(rt->vp.hit[pixel]);

	//data->color = vec_scale(COEF_OBJS, rgb_to_vec(data->rgb));
	if (data->dist < 0)
		return ;
	add_light_ambient(rt, data);
	if (data->type == TYPE_OBJ_NONE)
		return ;
	light = rt->prs->light;
	while (light)
	{
		data->ll = vec_sub(light->r, data->v);
		data->l = vec_unit(data->ll);
		prod = dot(data->n, data->l);
		if (prod > 0 && is_light_visible(rt, data))
		{
			data->temp = vec_scale(COEF_DIFF * light->brt * prod, \
				rgb_to_vec(light->rgb));
			data->color = vec_add(data->color, data->temp);
			data->r = vec_sub(vec_scale(2 * prod, data->n), data->l);
			prod = -1 * dot(data->r, data->ray);
			if (prod > EPSILON)  //????
			{
				prod = COEF_SPEC * light->brt * POW(prod, COEF_ALPHA);
				data->temp = vec_scale(prod, rgb_to_vec(light->rgb));
				data->color = vec_add(data->color, data->temp);
			}
		}
		light = light->next;
	}
	add_light_reflected_obj(rt, data);
	data->color = vec_prod(data->color, rgb_to_vec(data->rgb));
}
