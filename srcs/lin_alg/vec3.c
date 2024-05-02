#include "vec3.h"

/*
typedef struct s_vec3d
{
	t_num	x;
	t_num	y;
	t_num	z;
}	t_vec3d;
*/

t_vec3d	vec_def(t_num x, t_num y, t_num z)
{
	t_vec3d	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vec3d	vec_add(t_vec3d a, t_vec3d b)
{
	t_vec3d	p;

	p.x = a.x + b.x;
	p.y = a.y + b.y;
	p.z = a.z + b.z;
	return (p);
}

t_vec3d	vec_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d	p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.z = a.z - b.z;
	return (p);
}

t_num	dot(t_vec3d a, t_vec3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3d	cross(t_vec3d a, t_vec3d b)
{
	t_vec3d	cp;

	cp.x = a.y * b.z - a.z * b.y;
	cp.y = a.z * b.x - a.x * b.z;
	cp.z = a.x * b.y - a.y * b.x;
	return (cp);
}
