#include "vec3.h"

#define TAN tan

#define ASPECT_RATIO 1
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT 400

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307


typedef struct s_viewport
{
//	t_camera *cam;
	int width;
	int	height;
	t_num focal_length;
	t_vec3d center;
	t_vec3d **rays;
}	t_viewport;

int main()
{
	t_num foc_len = 1.0;
	t_num foc = 90;
	//t_num	v_x = 2 * foc_len * TAN(foc / 2);
	t_num	v_x = 2 * foc_len * tan(PI * foc / 180 / 2);
	t_num	v_y = v_x;
	int n_x = 10;
	int n_y = 10;

  t_vec3d	vec_z = (t_vec3d){0, 0, foc_len};
  t_vec3d	vec_x = (t_vec3d){v_x, 0, 0};
	t_vec3d	vec_y = (t_vec3d){0, -v_y, 0};

	int i = n_x - 1;
	int j = n_y - 1;
	t_vec3d	r_vec;
	r_vec = vec_add(vec_z, 
			vec_scale((t_num)(2 * i - n_x + 1) / (2 * (n_x - 1)), vec_x));
	r_vec = vec_add(r_vec, 
			vec_scale((t_num)(2 * j - n_y + 1) / (2 * (n_y - 1)), vec_y));

	printf("v_x=%lf", v_x);
	vec_print("r_vec", r_vec);


	return (0);
}
