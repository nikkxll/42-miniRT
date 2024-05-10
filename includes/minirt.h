/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:09:21 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/10 19:27:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"
# include "defines.h"

/*_____ Cleaning _____*/

void	generic_errors_handler(char *msg, int status, t_minirt *rt);
void	gnl_errors_handler(int status, t_minirt *rt);
void	cleaner(t_minirt *rt);

/*_____ Parsing _____*/

void	parser(char **av, t_minirt *rt);

double	custom_atof(char *c, double int_prt, double dec_prt, t_minirt *rt);
int		protected_atoi(char *str, t_minirt *rt);

void	process_args_w_sp_ht(char *line, char *entities[ARGS_MAX], int count);
t_bool	process_args_w_commas(char *line, char *entities[ARGS_MAX], int count);

void	init_struct(t_minirt **rt);
void	init_element(t_minirt *rt);
void	init_r(char *entities[ARGS_MAX], t_minirt *rt);
void	init_a(char *entities[ARGS_MAX], t_minirt *rt);
void	init_c(char *entities[ARGS_MAX], t_minirt *rt);
void	init_l(char *entities[ARGS_MAX], t_minirt *rt, int spec);
void	init_sp(char *entities[ARGS_MAX], t_minirt *rt);
void	init_pl(char *entities[ARGS_MAX], t_minirt *rt);
void	init_cy(char *entities[ARGS_MAX], t_minirt *rt);
void	init_co(char *entities[ARGS_MAX], t_minirt *rt);

void	rgb_check(int r, int g, int b, t_minirt *rt);
void	coord_check(double x, double y, double z, t_minirt *rt);
void	orient_vec_check(double x, double y, double z, t_minirt *rt);

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
t_vec3d	vec_prod(t_vec3d a, t_vec3d b);
void	vec_print(char *str, t_vec3d vec);

//viewport.c
void	init_viewport(t_minirt *rt);

void	hit_scene(t_minirt *rt);

// make_norm_vec.c
void	make_norm_vec(t_minirt *rt);

// lighting.c
t_rgb3	vec_to_rgb(t_vec3d c);
void lighting(t_minirt *rt, int pixel);

// transform_scene.c
void	transform_scene(t_minirt *rt);

// hit_sphere.c
t_num	dist_to_sphere(t_sphere *sp, t_vec3d v);
void	hit_spheres(t_minirt *rt, size_t pixel);
t_hit_data	touch_spheres(t_minirt *rt, t_hit_data *data, t_vec3d l);

// hit_plane.c
void	hit_planes(t_minirt *rt, size_t pixel);
t_hit_data	touch_planes(t_minirt *rt, t_hit_data *data, t_vec3d l);

//hit_cylin.c
void hit_cylinder(t_minirt *rt, size_t pixel);
t_hit_data	touch_cylinder(t_minirt *rt, t_hit_data *data, t_vec3d l);
t_num	dist_to_cylin(t_vec3d v0, t_vec3d v1, t_cylinder *obj, t_dist_cc *p);

#endif
