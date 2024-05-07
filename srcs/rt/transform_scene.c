#include "../../includes/minirt.h"

void	transform_general(t_camera *cam, t_num angles[2])
{
	// t_num			alpha;
	// t_num			beta;
	//t_num			gamma;

	angles[ALPHA] = 0;
	angles[BETA] = 0;
	// fix camera orintation flip in case r.x =0  or r.y = 0 and probably r.z=0
	//if (cam->r.x == 0 && cam->r.y == 0)
//		return ;
//	if (cam->r.y != 0);
	angles[ALPHA] = atan2(cam->n.x, cam->n.y) * 180 / PI;
	printf("alpha=%lf degree\n", angles[ALPHA]);
	angles[BETA] = acos(vec_unit(cam->n).z) * 180 / PI;
	printf("beta=%lf degree\n", angles[BETA]);
}

void	transform_spheres(t_sphere *sphere, t_camera *cam, t_num angles[2])
{
	t_sphere	*s;

	s = sphere;
	while (s)
	{
		s->r = vec_sub(s->r, cam->r);
		s->r = vec_rot_z(s->r, angles[ALPHA]);
		s->r = vec_rot_x(s->r, angles[BETA]);
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
		pl->r = vec_rot_z(pl->r, angles[ALPHA]);
		pl->r = vec_rot_x(pl->r, angles[BETA]);
		pl->n = vec_rot_z(pl->n, angles[ALPHA]);
		pl->n = vec_rot_x(pl->n, angles[BETA]);
		pl = pl->next;
	}
}

void	transform_scene(t_minirt *rt)
{
	t_num	angles[2];

	transform_general(rt->prs->camera, angles);
	transform_spheres(rt->prs->sphere, rt->prs->camera, angles);
	transform_planes(rt->prs->plane, rt->prs->camera, angles);
}
