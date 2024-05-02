#include "vec3.h"

#define TAN tan

#define ASPECT_RATIO 2
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT 400

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307


typedef struct s_viewport
{
//	t_camera *cam;
	int		foc;
	int		n_x;
	int		n_y;
	int		size;
	t_vec3d	*rays;
}	t_viewport;

t_vec3d	viewport_vec(t_viewport *vp, int i, int j)
{
	t_vec3d	r_vec;
	t_num	v_x;
	t_num	v_y;

	v_x = 2 * TAN(PI * vp->foc / 180 / 2);
	v_y = v_x / ASPECT_RATIO;
	r_vec = vec_add((t_vec3d){0, 0, 1},
			vec_scale((t_num)(2 * i - vp->n_x + 1) / (2 * (vp->n_x - 1)), 
				(t_vec3d){v_x, 0, 0}));
	r_vec = vec_add(r_vec,
			vec_scale((t_num)(2 * j - vp->n_y + 1) / (2 * (vp->n_y - 1)), 
				(t_vec3d){0, -v_y, 0}));
	r_vec = vec_unit(r_vec);
	return (r_vec);
}

void init_ray_bunch(t_viewport *vp)
{
	int i;
	int j;
	int n;

	vp->size = vp->n_x * vp->n_y;
	vp->rays = (t_vec3d *)malloc(sizeof(*vp->rays) * vp->size);
	i = 0;
	j = 0;
	n = 0;
	while (i < vp->n_x)
	{
		j = 0;
		while (j < vp->n_y)
		{
			vp->rays[n] = viewport_vec(vp, i, j);
			printf("i=%d, j=%d, n=%d,  ", i, j, n);
			vec_print("vp->rays[n]", vp->rays[n]);
			printf("r^2=  %.02f\n", vec_norm(vp->rays[n]));
			j++;
			n++;
		}
		i++;
	}
}

int main()
{
	t_viewport screen;

	t_num foc = 90;
	int	n_x = 4;
	int n_y = 4;

	screen = (t_viewport){foc, n_x, n_y, n_x * n_y, NULL};
	init_ray_bunch(&screen);

	return (0);
}
