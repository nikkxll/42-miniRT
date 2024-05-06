/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:09:21 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/06 11:47:13 by dnikifor         ###   ########.fr       */
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
void	vec_print(char *str, t_vec3d vec);

//viewport.c
void	init_viewport(t_viewport *vp);
t_num	dist_to_sphere(t_sphere *sp, t_vec3d v);
void	hit_scene(t_minirt *rt);

// transform_scene.c
void	transform_scene(t_minirt *rt);

#endif