/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:54:26 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/11 18:54:30 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_light_ambient(t_minirt *rt, t_hit_data *data)
{
	t_am_light	*a;

	a = rt->prs->aml;
	data->color = vec_add(data->color, \
		vec_scale(COEF_AMBI * a->ratio, rgb_to_vec(a->rgb)));
}

/*
void add_light_reflected_obj(t_minirt *rt, t_hit_data *data)
{
	t_vec3d	c;

	c = touch_spheres(rt, data, data->r).color;
	c = vec_scale(COEF_REFLECT * 10000, c);
	data->color = vec_add(data->color, c);
}
*/

int	is_light_visible(t_minirt *rt, t_hit_data *data)
{
	data->obst = -1;
	touch_spheres(rt, data, data->l);
	touch_planes(rt, data, data->l);
	touch_cylinder(rt, data, data->l);
	if (data->obst > EPSILON && data->obst + EPSILON < vec_norm(data->ll))
		return (0);
	return (1);
}

void	add_light_diff_spec(t_minirt *rt, t_hit_data *data, t_light *light)
{
	t_num		prod;

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
		if (prod > EPSILON)
		{
			prod = COEF_SPEC * light->brt * POW(prod, COEF_ALPHA);
			data->temp = vec_scale(prod, rgb_to_vec(light->rgb));
			data->color = vec_add(data->color, data->temp);
		}
	}
}

void	lighting(t_minirt *rt, int pixel)
{
	t_hit_data	*data;
	t_light		*light;

	data = &(rt->vp.hit[pixel]);
	if (data->dist < 0)
		return ;
	add_light_ambient(rt, data);
	if (data->type == TYPE_OBJ_NONE)
		return ;
	light = rt->prs->light;
	while (light)
	{
		add_light_diff_spec(rt, data, light);
		light = light->next;
	}
	//add_light_reflected_obj(rt, data);
	data->color = vec_prod(data->color, rgb_to_vec(data->rgb));
}
