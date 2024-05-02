/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 21:22:12 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef float	t_num;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef struct s_am_light
{
	int					type;
	double				ratio;
	t_rgb3				rgb;
	struct s_am_light	*next;
}	t_am_light;

typedef struct s_camera
{
	int				type;
	t_vec3d			r;
	t_vec3d			n;
	double			fov;
	struct s_camera	*next;
}	t_camera;

typedef struct s_light
{
	int				type;
	t_vec3d			r;
	double			brt;
	t_rgb3			rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	int				type;
	t_vec3d			r;
	double			d;
	t_rgb3			rgb;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int					type;
	t_vec3d				r;
	t_vec3d				n;
	t_rgb3				rgb;
	struct s_plane		*next;
}	t_plane;

typedef struct s_cylinder
{
	int					type;
	t_vec3d				r;
	t_vec3d				n;
	double				d;
	double				h;
	t_rgb3				rgb;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_parse
{
	t_am_light	*aml;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_parse;

typedef struct s_clean
{
	int	type;
	struct s_clean	*next;
}	t_clean;

typedef struct s_minirt
{
	t_parse			*prs;
	int				status;
	char			*line;
}	t_minirt;

#endif