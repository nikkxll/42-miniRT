#include "../../includes/structs.h"
#include "../../includes/vec3.h"

t_vec3d	viewport_vec(t_viewport *vp, int i, int j)
{
	t_vec3d	r_vec;
	t_num	v_x;
	t_num	v_y;

	v_x = 2 * TAN(PI * vp->foc / 180 / 2);
	v_y = v_x * IMAGE_HIGHT / IMAGE_WIDTH;
	r_vec = vec_add((t_vec3d){0, 0, 1},
			vec_scale((t_num)(2 * i - vp->n_x + 1) / (2 * (vp->n_x - 1)),
				(t_vec3d){v_x, 0, 0}));
	r_vec = vec_add(r_vec,
			vec_scale((t_num)(2 * j - vp->n_y + 1) / (2 * (vp->n_y - 1)),
				(t_vec3d){0, -v_y, 0}));
	r_vec = vec_unit(r_vec);
	return (r_vec);
}

void	init_ray_bunch(t_viewport *vp)
{
	int	i;
	int	j;
	int	n;

	vp->size = vp->n_x * vp->n_y;
	vp->rays = (t_vec3d *)malloc(sizeof(*vp->rays) * vp->size);
	n = 0;
	j = -1;
	while (++j < vp->n_y)
	{
		i = -1;
		while (++i < vp->n_x)
		{
			vp->rays[n] = viewport_vec(vp, i, j);
		/*	printf("i=%d, j=%d, n=%d,  ", i, j, n);
			vec_print("vp->rays[n]", vp->rays[n]);
			printf("r^2=  %.02f\n", vec_norm(vp->rays[n]));
		*/
			n++;
		}
	}
}

t_num	hit_distance_t_sphere(t_sphere *sp, t_vec3d v)
{
	t_num	denom;
	t_num	prod;
	t_num	t[2];

	prod = dot(v, sp->r);
	denom = prod * prod - dot2(sp->r) + POW(sp->d, 2) / 4;
	if (denom < EPSILON)
		return (-1);
	t[0] = SQRT(denom);
	t[1] = (-1) * t[0];
	t[0] += prod;
	t[1] += prod;
	if (t[1] > EPSILON)
		return (t[1]);
	if (t[0] > EPSILON)
		return (t[0]);
	return (0);
}
/*
int main()
{
	t_viewport screen;

	t_num foc = 90;
	int	n_x = 3;
	int n_y = 3;
	screen = (t_viewport){foc, n_x, n_y, n_x * n_y, NULL};

	t_vec3d r = {0, 0, 5};
	t_rgb3	col = {100, 100, 100};
	t_sphere sp = {0, r, 2.0, col, NULL};
	init_ray_bunch(&screen);

	t_num t;
	t = hit_distance_t_sphere(&sp, screen.rays[4]);
	printf("t=%f\n", t);




	return (0);
}
*/