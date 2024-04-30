#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef float	t_num;

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
	int	b;
}	t_col;

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
	t_col	c;
}	t_plane;

typedef struct s_obj
{
	int	type;
}	t_obj;

//vec3.c
t_vec3d	vec_def(double x, double y, double z);
t_vec3d	vec_add(t_vec3d a, t_vec3d b);
t_vec3d	vec_sub(t_vec3d a, t_vec3d b);
t_num	dot(t_vec3d a, t_vec3d b);
t_vec3d	cross(t_vec3d a, t_vec3d b);

// rotation_xyz.c
t_num	distance(t_vec3d p1, t_vec3d p2);
t_vec3d	vec_rot_x(t_vec3d vec, t_num angle);
t_vec3d	vec_rot_y(t_vec3d vec, t_num angle);
t_vec3d	vec_rot_z(t_vec3d vec, t_num angle);