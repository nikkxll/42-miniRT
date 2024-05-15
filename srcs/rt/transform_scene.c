/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:48:36 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/15 14:38:33 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotatate_vector(t_vec3d *v, t_num angles[2])
{
	if (fabs(angles[ALPHA]) < 45)
	{
		*v = vec_rot_z(*v, -angles[ALPHA]);
		*v = vec_rot_x(*v, -angles[BETA]);
		return ;
	}
	if (angles[ALPHA] < -45)
	{
		*v = vec_rot_z(*v, -(90 + angles[ALPHA]));
		*v = vec_rot_y(*v, - angles[BETA]);
		return ;
	}
	*v = vec_rot_z(*v, 90.0 - angles[ALPHA]);
	*v = vec_rot_y(*v, angles[BETA]);
}

void	transform_spheres(t_sphere *sphere, t_camera *cam, t_num angles[2])
{
	t_sphere	*s;

	s = sphere;
	while (s)
	{
		s->r = vec_sub(s->r, cam->r);
		rotatate_vector(&(s->r), angles);
		s = (t_sphere *)s->next;
	}
}

void	transform_light(t_light *light, t_camera *cam, t_num angles[2])
{
	t_light	*s;

	s = light;
	while (s)
	{
		s->r = vec_sub(s->r, cam->r);
		rotatate_vector(&(s->r), angles);
		s = s->next;
	}
}

void	transform_planes(t_plane *plane, t_camera *cam, t_num angles[2])
{
	t_plane	*pl;

	pl = plane;
	while (pl)
	{
		pl->r = vec_sub(pl->r, cam->r);
		rotatate_vector(&(pl->r), angles);
		pl->n = vec_unit(pl->n);
		rotatate_vector(&(pl->n), angles);
		pl = pl->next;
	}
}

void	transform_scene(t_minirt *rt)
{
	t_num		angles[2];
	t_camera	*cam;

	angles[ALPHA] = 0;
	angles[BETA] = 0;
	cam = rt->prs->camera;
	angles[ALPHA] = atan2(cam->n.x, cam->n.y) * 180 / M_PI;
	angles[BETA] = acos(vec_unit(cam->n).z) * 180 / M_PI;
	printf("-- Rotation: alpha = %lf\n", angles[ALPHA]);
	printf("-- Rotation: beta = %lf\n", angles[BETA]);
	transform_spheres(rt->prs->sphere, cam, angles);
	transform_light(rt->prs->light, cam, angles);
	transform_planes(rt->prs->plane, cam, angles);
	transform_planes((t_plane *)rt->prs->cylinder, cam, angles);
	transform_planes((t_plane *)rt->prs->cone, cam, angles);
}
