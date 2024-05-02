#include "vec3.h"

t_num	vec_norm(t_vec3d v)
{
	return ((t_num)sqrt(dot(v, v)));
}

t_vec3d	vec_unit(t_vec3d p)
{
	t_vec3d	nv;
	t_num	norm;

	norm = vec_norm(p);
	nv.x = p.x / norm;
	nv.y = p.y / norm;
	nv.z = p.z / norm;
	return (nv);
}

t_num	vec_sin(t_vec3d a, t_vec3d b)
{
	return (sqrt(1 - pow(vec_cos(a, b), 2)));
}

t_num	vec_cos(t_vec3d a, t_vec3d b)
{
	return (dot(a, b) / (vec_norm(a) * vec_norm(b)));
}

t_vec3d	vec_scale(t_num n, t_vec3d p)
{
	t_vec3d	v;

	v.x = n * p.x;
	v.y = n * p.y;
	v.z = n * p.z;
	return (v);
}

void	vec_print(char *str, t_vec3d vec)
{
	printf("%s = (%f, %f, %f)\n",str, (float)vec.x, (float)vec.y, (float)vec.z);
}
