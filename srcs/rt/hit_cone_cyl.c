#include "../../includes/minirt.h"

int	is_epsilon(t_num	a)
{
	if (-EPSILON < a && a < EPSILON)
		return (1);
	return (0);
}

t_num	solve_positive(t_num a, t_num b, t_num c)
{
	t_num	t[2];

	if (is_epsilon(a))
	{
		if (is_epsilon(b))
			return ((t_num)(is_epsilon(c) - 1));
		t[0] = - c / b;
		return ((1 - is_epsilon(t[0])) * t[0]);
	}
	t[0] = b * b - 4 * a * c; 
	if (t[0] < EPSILON)
		return (-1);
	t[1] = (-b - t[0])/ a / 2;
	if (t[1] > EPSILON)
		return (t[1]);
	t[1] = (-b + t[0])/ a / 2;
	if (t[1] > EPSILON)
		return (t[1]);
	return (0); // or -1 ??
}

void	init_dist_cc(t_dist_cc *var, t_vec3d v0, t_vec3d v, t_cylinder *obj)
{
		var->k1 = 1;
		var->k2 = 0;
	if (obj->type == CYLINDER)
		var->k2 = obj->d * obj->d /4;
	else if (obj->type == 111111) //replace by CONE
		var->k1 = 1 + obj->d * obj->d / obj->h / obj->h;
	var->cprime = vec_sub(obj->r, v0);
	var->vn = dot(v, obj->n);
	var->cn = dot(var->cprime, obj->n);
	var->cv = dot(var->cprime, v);
	var->c2 = dot2(var->cprime);
}

t_num	dist_to_cone_cyli(t_vec3d v0, t_vec3d v1, t_cylinder *obj)
{
	t_num			t;
	t_num			hight2;
	t_dist_cc v;

	init_dist_cc(&v, v0, v1, obj);
	t = solve_positive(1 - v.k1 * v.vn *v.vn, \
		v.cv - v.k1 * v.vn *v.cn, v.c2 - v.k1 * v.cn * v.cn - v.k2);
	if (t < 0)
		return (t);
	hight2 = t * t * v.vn * v.vn - 2 * v.vn * v.cn * t + v.cn * v.cn;
	if (hight2 + EPSILON < obj->h * obj->h /4)
		return (t);
	return (-1);
}

void	hit_cylinder(t_minirt *rt, size_t pixel)
{//modify the code
	t_num		t;
	t_sphere	*s;
	t_hit_data	*data;

	data = &(rt->vp.hit[pixel]);
	s = rt->prs->sphere;
	while (s)
	{
		t = dist_to_sphere(s, data->ray);
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

t_hit_data	touch_cylinder(t_minirt *rt, t_hit_data *data, t_vec3d l)
{//modify the code
	t_hit_data	ret;
	t_num		t;
	t_sphere	*s;
	t_sphere	copy;

	ret.dist = -1;
	s = rt->prs->sphere;
	while (s)
	{
		copy = *s;
		copy.r = vec_sub(copy.r, data->v);
		t = dist_to_sphere(&copy, l);
		if (t > EPSILON && (data->obst == -1 || t < data->obst))
		{
			data->obst = t;
			ret.dist = t;
			ret.obj = (t_obj *)s;
			ret.type = SPHERE;
			ret.rgb = s->rgb; 
		/*	if (t < vec_norm(data->ll))
			{
			//	printf("t=%lf, light distance =%lf\n", t, vec_norm(data->ll));
				break;
			}
		*/
		}
		s = s->next;
	}
	return (ret);
}
