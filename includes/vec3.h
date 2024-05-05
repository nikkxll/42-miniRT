#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

#define TAN tan
#define POW pow
#define SQRT sqrt

#define IMAGE_WIDTH 700
#define IMAGE_HIGHT 500

#define MLXWIDTH 700
#define MLXHEIGHT 700
#define CHANNELBACK 100

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307
#define EPSILON 0.0000000000000001

//typedef float	t_num;

//vec3.c
t_vec3d	vec_def(t_num x, t_num y, t_num z);
t_vec3d	vec_add(t_vec3d a, t_vec3d b);
t_vec3d	vec_sub(t_vec3d a, t_vec3d b);
t_num	dot(t_vec3d a, t_vec3d b);
t_num	dot2(t_vec3d a);
t_vec3d	cross(t_vec3d a, t_vec3d b);

// rotation_xyz.c
t_num	distance(t_vec3d p1, t_vec3d p2);
t_vec3d	vec_rot_x(t_vec3d vec, t_num angle);
t_vec3d	vec_rot_y(t_vec3d vec, t_num angle);
t_vec3d	vec_rot_z(t_vec3d vec, t_num angle);

//vec_utils.c
t_num	vec_norm(t_vec3d v);
t_vec3d	vec_unit(t_vec3d p);
t_num	vec_sin(t_vec3d a, t_vec3d b);
t_num	vec_cos(t_vec3d a, t_vec3d b);
t_vec3d	vec_scale(t_num n, t_vec3d p);
void	vec_print(char *str, t_vec3d vec);

//viewport.c
void	init_viewport(t_viewport *vp);
t_num	dist_to_sphere(t_sphere *sp, t_vec3d v);
void	hit_scene(t_minirt *rt);
