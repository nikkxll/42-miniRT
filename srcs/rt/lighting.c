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

void lighting(t_minirt *rt, int pixel)
{
	t_hit_data	*data;
	t_light		*light;
	t_am_light	*a;
	t_vec3d		l;
	t_num		prod;
	int i = 0;

	data = &(rt->vp.hit[pixel]);
	data->color = vec_scale(COEF_OBJS, rgb_to_vec(data->rgb));
	if (data->dist < 0)
		return ;
	a = rt->prs->aml;
	data->color = vec_add(data->color, \
		vec_scale(COEF_AMBI * a->ratio, rgb_to_vec(a->rgb)));
	light = rt->prs->light;
	while (light)
	{
		l = vec_unit(vec_sub(light->r, vec_scale(data->dist, data->ray)));
		if (pixel == 0)
				printf("i=%d, size/2=%d\n", i++, rt->vp.size / 2);
		prod = dot(data->n, l);
		if (prod > 0)
		{
			data->temp = vec_scale(COEF_DIFF * light->brt * prod, \
				rgb_to_vec(light->rgb));
			data->color = vec_add(data->color, data->temp);
			data->temp = vec_sub(vec_scale(2 * prod, data->n), l);
			prod = dot(data->temp, vec_unit(vec_scale(data->dist, data->ray)));
//			printf("prod=%lf\n",prod);
			if (1) //prod > 0)
			{
		//		printf("prod=%lf\n", prod);
				prod = COEF_SPEC * light->brt * POW(prod, COEF_ALPHA);
				data->temp = vec_scale(prod, rgb_to_vec(light->rgb));
				data->color =vec_add(data->color, data->temp);
			}
		}
		light = light->next;
	}
}
