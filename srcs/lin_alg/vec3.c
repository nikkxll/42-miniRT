////#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef float t_num;  //norms???

typedef enum e_obj_type
{
	SPHERE,
	PLANE
}	t_obj_type;

typedef struct s_vec3d
{
	t_num	x;
	t_num	y;
	t_num	z;
}	t_vec3d;

typedef struct s_col
{
	int	r;
	int	g;
	int b;
} t_col;

typedef struct s_sphere
{
	int		type;
	t_num	d;
	t_vec3d	r;
	t_col	c;
}	t_sphere;

typedef struct s_plane
{
	int		type;
	t_vec3d	r;
	t_vec3d	n;
	t_col 	c;
}	t_plane;


typedef struct s_obj
{
	int	type;
} t_obj;

t_num	take_x_from_sphere(t_sphere *sphere)
{
	return (sphere->r.x);
}

t_num	take_x_from_plane(t_plane *plane)
{
	return (plane->r.x);
}

t_num	take_x(t_obj *obj)
{
	t_num ret;

	if (obj->type == SPHERE)
		ret = take_x_from_sphere((t_sphere*)obj);
	else if (obj->type == PLANE)
		ret =take_x_from_plane((t_plane*)obj);
	return (ret);
}

int main()
{
	t_sphere s;
	t_plane p;
	t_obj *o[2];

	s.r.x = 1;
	s.type = SPHERE;
	p.r.x = 2;
	p.type = PLANE;
	o[0] = (t_obj*)&s;
	o[1] = (t_obj*)&p;

	printf("sphere's x =%f\n", take_x(o[0]));
	printf("plane's x =%f\n", take_x(o[1]));

	return (1);
}
