/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/01 00:02:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef float	t_num;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

typedef struct s_vec3d
{
	t_num	x;
	t_num	y;
	t_num	z;
}	t_vec3d;

typedef struct s_am_light
{
	int			type;
	float		ratio;
	t_rgb3		rgb;
	struct s_am_light	*next;
}	t_am_light;

typedef struct s_camera
{
	int			type;
	t_vec3d		coord;
	t_vec3d		orient;
	float		fov;
	struct s_camera	*next;
}	t_camera;

typedef struct s_light
{
	int		type;
	t_vec3d	coord;
	float	bright;
	t_rgb3	rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	int			type;
	t_vec3d		coord;
	float		d;
	t_rgb3		rgb;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int			type;
	t_vec3d		coord;
	t_vec3d		normal;
	t_rgb3		rgb;
	struct s_plane		*next;
}	t_plane;

typedef struct s_cylinder
{
	int			type;
	t_vec3d		coord;
	t_vec3d		normal;
	float		d;
	float		h;
	t_rgb3		rgb;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_collection
{
	t_am_light	*aml;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_collection;

typedef struct s_minirt
{
	t_collection	*col;
	int				status;
}	t_minirt;

#endif