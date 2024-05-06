#include "../../includes/structs.h"
#include "../../includes/vec3.h"

void	transform_spheres(t_sphere *sphere, t_camera *cam)
{
	t_sphere *s;
	t_num			alpha;
	t_num			beta;
	//t_num			gamma;
	
	alpha = 0;
	beta = 0;
	// fix camera orintation flip in case r.x =0  or r.y = 0 and probably r.z=0
	//if (cam->r.x == 0 && cam->r.y == 0)
//		return ;
//	if (cam->r.y != 0);
	alpha = atan2(cam->n.x, cam->n.y) * 180 / PI;
	printf("alpha=%lf degree\n", alpha);
	beta = acos(vec_unit(cam->n).z) * 180 / PI;
	printf("beta=%lf degree\n", beta);
	s = sphere;
	while (s)
	{
		s->r = vec_sub(s->r, cam->r);
		s->r = vec_rot_z(s->r, alpha);
		s->r = vec_rot_x(s->r, beta);
		s = s->next;
	}
}

void	transform_scene(t_minirt *rt)
{
	transform_spheres(rt->prs->sphere, rt->prs->camera);
	//transform_planes(rt->prs->sphere, rt->prs->camera);
}